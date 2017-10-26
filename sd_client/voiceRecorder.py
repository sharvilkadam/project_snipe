#!/usr/bin/env python
# vim:fileencoding=utf-8

import os
import time
import datetime
import numpy as np

import soundfile as sf
import pyaudio as pa

# global
wav = np.array([])

def callback(in_data, frame_count, time_info, status):
    global wav
    in_float = np.frombuffer(in_data, dtype=np.int16).astype(np.float)
    in_float[in_float > 0.0] /= float(2**15 - 1)
    in_float[in_float <= 0.0] /= float(2**15)
    wav = np.r_[wav, in_float]

    return (in_data, pa.paContinue)

if __name__ == "__main__":
    # set outfile
    outDir = './Record/'
    if not os.path.exists(outDir):
        os.makedirs(outDir)
    todaydetail  =    datetime.datetime.today()
    outFile = outDir + todaydetail.strftime("%Y-%m-%d-%H-%M-%S.wav")

    # pyaudio
    p_in = pa.PyAudio()
    bytes = 2
    py_format = p_in.get_format_from_width(bytes)
    fs = 44100
    #fs = 16000
    channels = 1
    chank_size = fs * 1
    use_device_index = -1
    #use_device_index = 5
    
    # find input device
    print()
    print("device num: {0}".format(p_in.get_device_count()))
    print()
    for i in range(p_in.get_device_count()):
        maxInputChannels = p_in.get_device_info_by_index(i)['maxInputChannels']
        if maxInputChannels > 0:
            print('### Found!: index = %d, maxInputChannels = %d' % (i, maxInputChannels))
            print(p_in.get_device_info_by_index(i))
            print()
            if use_device_index == -1:
                use_device_index = i
                fs = int(p_in.get_device_info_by_index(i)['defaultSampleRate'])
        else:
            print(p_in.get_device_info_by_index(i))
            print()

    print('use_device_index = ', use_device_index)
    print('SampleRate = ', fs)

    # create input stream
    in_stream = p_in.open(format=py_format,
                          channels=channels,
                          rate=fs,
                          input=True,
                          frames_per_buffer=chank_size,
                          input_device_index=use_device_index,
                          stream_callback=callback)

    in_stream.start_stream()

    # input loop while key input
    while in_stream.is_active():
        cc = input()
        if cc:
            in_stream.stop_stream()
            in_stream.close()
            p_in.terminate()
            break
        time.sleep(0.1)
    else:
        in_stream.stop_stream()
        in_stream.close()

    # save input sound
    sf.write(outFile, wav, fs)
