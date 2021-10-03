# Created by swagatobag2000

from pytube import YouTube
import pytube
import os

def main():

    video_url = input('Enter YouTube video URL: ')
    yt = YouTube(str(video_url))
    
    video = yt.streams.filter(only_audio=True).first()
    
    path = os.getcwd() + '\\'

    out_file = video.download(output_path=path)
    
    base, ext = os.path.splitext(out_file)
    new_file = base + '.mp3'
    os.rename(out_file, new_file)
    
    print(yt.title + " has been successfully downloaded.")

if __name__ == '__main__':
    main()