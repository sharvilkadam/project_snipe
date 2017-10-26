/*
 * main.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: pratik
 */

// -lopencv_core -lopencv_imgproc -lopencv_objdetect -lopencv_highgui
#include <iostream> // for standard I/O
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
#include <opencv2/core/core.hpp>     // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include<vector>
#include<cstdio>
#include "json/json.h"
#include <fstream>
#include <cstdlib>

#include <future>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;
using namespace cv;

#define DELAY 25
#define THRESHOLD 20
#define MAX_FRAMES 150
#define START_T 125
#define MAX_F_LIMIT 50000

int get_index(char c){
	if(c == 'h'){
		return 2;
	}
	if(c == 'm'){
		return 1;
	}
	return 0;
}

int get_data(char* fname){

	Json::Value people;
	std::ifstream people_file(fname, std::ifstream::binary);
	people_file >> people;

	cout << people << endl;
	double max_prob  = 0;
	int res = 0;
	
	cout << endl << fname << endl;
	double a = people["Predictions"][0]["Probability"].asDouble();
	std::string a_tag = people["Predictions"][0]["Tag"].asString();
	cout << a_tag << " : " << a << endl;
	double b = people["Predictions"][1]["Probability"].asDouble();
	std::string b_tag = people["Predictions"][1]["Tag"].asString();
	cout << b_tag << " : " << b << endl;
	double c = people["Predictions"][2]["Probability"].asDouble();
	std::string c_tag = people["Predictions"][2]["Tag"].asString();
	cout << c_tag << " : " << c << endl;

	if(a > b){
		if(a > c){
			return get_index(a_tag[0]);
		}
	} else{
		if(b > c){
			return get_index(b_tag[0]);
		}
	}
	return get_index(c_tag[0]);
}

int main(int argc, char *argv[]) {

	using namespace std::chrono_literals;

	const char* WIN_RF = "Reference";

	int num_hits = 3;
	if(argc > 1){
		num_hits = atoi(argv[1]);
		cout << "num hits: " << num_hits << endl;
	}

	stringstream conv;
	// const string sourceReference = argv[1];
	int frameNum = 0;          // Frame counter
	VideoCapture captRefrnc(0);
	if (!captRefrnc.isOpened()) {
		cout << "Could not open reference " << 0 << endl;
		return -1;
	}
	Size refS = Size((int) captRefrnc.get(CV_CAP_PROP_FRAME_WIDTH),
			(int) captRefrnc.get(CV_CAP_PROP_FRAME_HEIGHT));

	const char* WIN_PR = "Processed";
	// Windows
	namedWindow(WIN_RF, WINDOW_AUTOSIZE);

	moveWindow(WIN_RF, 0, 0);         //750,  2 (bernat =0)

	cout << "Reference frame resolution: Width=" << refS.width << "  Height="
			<< refS.height << " of nr#: "
			<< captRefrnc.get(CV_CAP_PROP_FRAME_COUNT) << endl;
	Mat frameReference;
	Mat image;
	Mat tmp;

	vector<vector<vector<unsigned long> > > sum(refS.height,
			vector<vector<unsigned long> >(refS.width,
					vector<unsigned long>(3, 0)));

	for(int t=0; t < num_hits; t++){
		for (int n = START_T; n > 0; n--) //Show the image captured in the window and repeat
			{
			captRefrnc >> frameReference;
			if (frameReference.empty()) {
				cout << " < < <  Game over!  > > > ";
				break;
			}

			char str3[50] = { 0 };
			sprintf(str3, "%d", n / 25);
			putText(frameReference, str3, Point2f(50, 100), FONT_HERSHEY_PLAIN, 5,
					Scalar(255, 255, 255, 255), 5);
			imshow(WIN_RF, frameReference);
			waitKey(40);

		}

		captRefrnc >> frameReference;
		imwrite("10.jpg", frameReference);

		frameReference.copyTo(tmp);

		char str4[50] = { 0 };
		sprintf(str4, "Analysing Frame...");

		putText(tmp, str4, Point2f(200, 500), FONT_HERSHEY_PLAIN, 2,
				Scalar(255, 255, 255, 255), 2);

		imshow(WIN_RF, tmp);
		waitKey(40);

		auto future = std::async(std::launch::async, [] {
	        system(
				"curl -v -X POST \"https://southcentralus.api.cognitive.microsoft.com/customvision/v1.0/Prediction/1e21a211-1afc-415b-a4aa-e1f757d6c3e7/image\" -H \"Content-Type:application/octet-stream\" -H \"Prediction-Key: 22d362eaea7949b98f3e832ea98a3ddd\" --data-binary @10.jpg -o 10.json");
	        return 8;
	    });

		// Use wait_for() with zero milliseconds to check thread status.
    	auto status = future.wait_for(0ms);

	    while (1) //Show the image captured in the window and repeat
		{
			status = future.wait_for(0ms);
		    if (status == std::future_status::ready) {
		        std::cout << "Thread finished" << std::endl;
		        break;
		    }
			captRefrnc >> frameReference;
			if (frameReference.empty()) {
				cout << " < < <  Game over!  > > > ";
				break;
			}
			imshow(WIN_RF, frameReference);
			waitKey(40);

		}

	    auto result = future.get(); // Get result.

		Json::Value people;
		std::ifstream people_file("10.json", std::ifstream::binary);
		people_file >> people;

		cout << people << endl;

		double withGun = 0;
		double withoutGun = 0;
		
		double a = people["Predictions"][0]["Probability"].asDouble();
		std::string a_tag = people["Predictions"][0]["Tag"].asString();
		double b = people["Predictions"][1]["Probability"].asDouble();
		std::string b_tag = people["Predictions"][1]["Tag"].asString();

		if(a_tag[4] == 'G'){
			withGun = a;
			withoutGun = b;
		}else{
			withGun = b;
			withoutGun = a;
		}

		cout << endl << endl;

		cout << "Probability withGun: " << withGun << endl;
		cout << "Probability withoutGun: " << withoutGun << endl;

		cout << endl << endl;

		if(withGun < withoutGun || withGun < 0.25){
			system("figlet OK");
		}else{
			system("figlet DANGER");

			// arm detection

			for (int n = START_T; n > 0; n--) //Show the image captured in the window and repeat
			{
				captRefrnc >> frameReference;
				if (frameReference.empty()) {
					cout << " < < <  Game over!  > > > ";
					break;
				}

				char str3[50] = { 0 };
				sprintf(str3, "%d", n / 25);
				putText(frameReference, str3, Point2f(50, 100), FONT_HERSHEY_PLAIN, 5,
						Scalar(255, 255, 255, 255), 5);
				imshow(WIN_RF, frameReference);
				waitKey(40);

			}

			// save 6 frames
			char fname[10] = "0.jpg";
			for (int n = 1; n <= 6; n++) //Show the image captured in the window and repeat
			{
				for(int m = 0; m < 8; m++){
					captRefrnc >> frameReference;
					if (frameReference.empty()) {
						cout << " < < <  Game over!  > > > ";
						break;
					}

					imshow(WIN_RF, frameReference);
					waitKey(40);
				}

				captRefrnc >> frameReference;
				fname[0] = n + '0';
				imwrite(fname, frameReference);
				cout << fname << "written..." << endl;
			}

			auto future = std::async(std::launch::async, [] {
					char cmd[1000] = {0};
					for(int z=1; z<=6; z++){
						sprintf(cmd, "curl -v -X POST \"https://southcentralus.api.cognitive.microsoft.com/customvision/v1.0/Prediction/da83ae8f-eaae-4078-bb60-71c9a3f13b5c/image\" -H \"Content-Type:application/octet-stream\" -H \"Prediction-Key: 22d362eaea7949b98f3e832ea98a3ddd\" --data-binary @%d.jpg -o %d.json", z, z);
			        	system(cmd);
					}
			        return 8;
			    });

			while (1) //Show the image captured in the window and repeat
			{
				status = future.wait_for(0ms);
			    if (status == std::future_status::ready) {
			        std::cout << "Thread finished" << std::endl;
			        future.get();
			        break;
			    }

				captRefrnc >> frameReference;
				if (frameReference.empty()) {
					cout << " < < <  Game over!  > > > ";
					break;
				}
				imshow(WIN_RF, frameReference);
				waitKey(40);

			}

			std::vector<int> arm_arr;
			char jname[10] = "0.json";
			for(int n=1; n<=6; n++){
				jname[0] = n + '0';
				arm_arr.push_back(get_data(jname));
			}

			cout << endl << "arm: ";
			for(int i : arm_arr){
				cout << i << ", ";
			}
			cout << endl;
			
			// send alert
			system("python gmail_email.py");
			system("figlet Alert");
			
			// -----------------


		}

		// waitKey(2000);

		cout << endl << "--- DONE ---" << endl;

	}

	while (1) //Show the image captured in the window and repeat
		{
		captRefrnc >> frameReference;
		if (frameReference.empty()) {
			cout << " < < <  Game over!  > > > ";
			break;
		}
		imshow(WIN_RF, frameReference);
		waitKey(40);

	}

	return 0;
}


