## Inspiration
In the aftermath of the recent mass shooting in Las Vegas, our prayers are with the 59 people who lost their lives and the 527 people who were badly injured.

But are our prayers sufficient? In this technology age, with machine learning and other powerful AI algorithms being invented and used heavily in systems all over the world, we took this opportunity provided by Cal Hacks to build something that has the potential to have a social impact on the world by aiming to prevent such incidents of mass shootings. 

## What it does?
**Snipe** is a real-time recognition system to prevent the use of illegal guns for evil purposes. 

Firstly, the system analyses real-time video feed provided by security cams or cell phone by sampling frames and detecting whether is there a person holding a gun/rifle in the frames. This detects a suspicious person holding a gun in public and alerts the watching security. Most of the guns used for malicious intent are bought illegally, this system can also be used to tackle this scenario (avoidance scenario). 

Secondly, it also detects the motion of the arm before someone is about to fire a gun. The system then immediately notifies the police and the officials via email and SMS, so that they can prepare to mobilize without delay and tackle the situation accordingly. 

Thirdly, the system recognizes the sound of a rifle/gun being fired and sounds an alarm in nearby locations to warn the people around and avoid the situation.

This system meant to aid the law enforcement to be more efficient and help people avoid such situations. This is an honest effort to use our knowledge in computer science in order to create something to make this world a better place.

## How we built it?
Our system relies on OpenCV to sample and process the real-time video stream for all machine learning components to use.

1) Image Recognition/ Object Detection: This component uses the powerful Microsoft's Cognitive Services API  and Azure to classify the frames. We trained the model using our custom data images. The sampled frames are classified on the cloud telling us whether is there a gun bearing human in the image with a probability distribution.

2) Arm Motion recognition: The Arm Motion detection detects whether a person is about to fire a gun/rifle. It also uses the Microsoft's custom vision cognitive API to detect the position of the arms. We use an optimized algorithm on the client side to detect whether the returned probability distribution from API represents the gun firing motion.

3) Sound Detection: Finally to detect the sound of a rifle/gun been fired, we use NEC's sound recognition API to detect the same. Once the program detects that the API returned true for the sound chunk, we sound an alarm to warn people.

The entire application was built in C++.

## Challenges we ran into
Machine learning algorithms need a lot of data for training in order to get highly accurate results. This being a limited time hackathon, we found it hard to collect a lot of data to achieve the desired high accuracy of classification. But we managed to train the model reasonably well (around 80% accuracy in object detection, around 75% in arm motion detection) using the time we had to collect the required data. 

## Accomplishments that we're proud of
The issue of mass shootings is pressing globally. We are proud to achieve a solution for the same that has a practical application. Our system may not be perfect but if it can prevent even 1 of 5 shooting incidents, then we are on the right route to accomplish our mission. The social impact that our product can have is inspiring for us and hopefully, it motivates other hackers to build applications that can truly have a positive impact on the world.

## What we learned?
Hackathons are a great way to develop something cool and useful in a day or two. Thanking CalHacks for hosting such a great event and helping us network with the industry's brightest and fellow hackers. Machine learning is the future of computing and using it for our project was a great experience.

## What's next for Snipe?
With proper guidance from our university's professors, we aim to better the machine learning algorithms and get better results. In the future scope, we plan to include emotion and behavior detection in the system to improve it further in detecting suspicious activity before a mishap.