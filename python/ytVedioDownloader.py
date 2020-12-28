#!/usr/bin/python3

import pytube
from pytube import YouTube

def downloadVideo():
	myURL = input("Please paste in the URL of the video you want to download: ")
	if type(myURL) == str:
		yt = YouTube(myURL)
		video = yt.streams.first()
		location = input("Please specify the directory you want to save the video to: ")
		if type(location) == str:
			video.download(location)
			print("Video downloaded successfuly")
		else: 
			print("Please enter a vaid location")
			downloadVideo()

	else:
		print("Please enter a valid URL")
		downloadVideo()

downloadVideo()