import tkinter as tk
from tkinter import ttk
from tkinter import *
from tkinter import messagebox, filedialog
from pytube import YouTube
from pytube.exceptions import RegexMatchError
from urllib.error import URLError


def Widgets():
    link_label = Label(root, text="YouTube link :", bg="#F8EEF5")
    link_label.grid(row=1, column=0, pady=5, padx=5)

    root.linkText = Entry(root, width=55, textvariable=video_Link)
    root.linkText.grid(row=1, column=1, pady=5, padx=5)

    destination_label = Label(root, text="Destination :", bg="#F8EEF5")
    destination_label.grid(row=2, column=0, pady=5, padx=5)

    root.destinationText = Entry(root, width=55, textvariable=download_Path)
    root.destinationText.grid(row=2, column=1, pady=5, padx=5)

    browse_B = Button(root, text="Browse", command=Browse, width=10, bg="#E9D878")
    browse_B.grid(row=2, column=2, pady=5, padx=5)

    getRes_B = Button(root, text="Get Resolutions", command=getResolution, width=15, bg="#E58ECB")
    getRes_B.grid(row=3, column=1, pady=5, padx=5)


def Browse():
    download_Directory = filedialog.askdirectory(initialdir="Default")
    download_Path.set(download_Directory)


def getResolution():
    try:
        resolution_temp = []
        Youtube_link = video_Link.get()
        getVideo = YouTube(Youtube_link)
        for i in getVideo.streams.filter(progressive=True, subtype='mp4'):
            resolution_temp.append(str(i.resolution))
        resolution_avail = list({res for res in resolution_temp if res != 'None'})

        resolution_label = Label(root, text="Select Resolution: ", bg="#F8EEF5")
        resolution_label.grid(row=4, column=0, pady=5, padx=5)

        resolutionSelect = ttk.Combobox(root, width=20, textvariable=resolution)
        resolutionSelect['values'] = resolution_avail
        resolutionSelect.grid(row=4, column=1, pady=5, padx=5)
        resolutionSelect.current()

        Download_B = Button(root, text="Download", command=Download, width=20, bg="#E58ECB")
        Download_B.grid(row=5, column=1, pady=3, padx=3)

    except RegexMatchError:
        messagebox.showinfo("UNSUCCESSFUL", "PLEASE ENTER VALID LINK")
    except URLError:
        messagebox.showinfo("UNSUCCESSFUL", "PLEASE CHECK YOUR INTERNET CONNECTION")


def Download():
    Youtube_link = video_Link.get()
    download_Folder = download_Path.get()
    getVideo = YouTube(Youtube_link)
    videoStream = getVideo.streams.filter(progressive=True, subtype='mp4', resolution=resolution.get()).first()
    videoStream.download(download_Folder)
    messagebox.showinfo("SUCCESSFULLY", "DOWNLOADED AND SAVED IN\n" + download_Folder)


root = tk.Tk()

root.geometry("700x200")
root.resizable(False, False)
root.title("YouTube Video Downloader")
root.config(background="#F8EEF5")

video_Link = StringVar()
download_Path = StringVar()
resolution = StringVar()

Widgets()
root.mainloop()
