import re
import pandas as pd
import docx2txt
import RAKE
import datetime
from tkinter import *

text = docx2txt.process("sample.docx")
sentences = re.split('\n',text)
dataset_sentences=pd.DataFrame(sentences,columns=["sentences"])
null_sentences=dataset_sentences["sentences"]!=''
dataset_sentences=dataset_sentences[null_sentences]
final_sentence = []
for sent in dataset_sentences["sentences"]:
    final_sentence.append(sent.lstrip('0123456789. '))

stopwords="stopwords.txt"
rake_object = RAKE.Rake(stopwords)

keywords_freq=rake_object.run(text)
keywords = [i[0] for i in keywords_freq if i[1]>2]
keywords.sort()

date=datetime.datetime.now()
date_name=str(date.year)+str(date.strftime("%m"))+str(date.strftime("%d"))+str(date.strftime("%H"))+str(date.strftime("%M"))+str(date.strftime("%S"))+str(date.strftime("%f"))

root = Tk()
root.title("Search and Display")

mainframe = Frame(root)
mainframe.grid(column=0,row=0, sticky=(N,W,E,S) )
mainframe.columnconfigure(0, weight = 1)
mainframe.rowconfigure(0, weight = 1)
mainframe.pack(pady = 100, padx = 100)

tkvar = StringVar(root)
tkvar.set('Select a Keyword') # set the default option

popupMenu = OptionMenu(mainframe, tkvar, *keywords)
Label(mainframe, text="Choose a Keyword",justify=LEFT).grid(row = 1, column = 1)
popupMenu.grid(row = 2, column =1)

xxx=Label(text="")
xxx.pack(side='top')
yyy=Label(text="")
yyy.pack(side='top')

def change_dropdown(*args):

    xxx.configure(text=tkvar.get(), justify=LEFT,wraplength=1000)
    temp=""

    for line in final_sentence:

        if re.match("(.*)"+tkvar.get()+"(.*)",line.lower()):

            temp+="\n\n"+line

            text_file=open("output_"+date_name+".txt",'a')
            text_file.write(tkvar.get())
            text_file.write(" :  \n")
            text_file.write(line)
            text_file.write("\n\n")
            text_file.close()

        yyy.configure(text=temp, justify=LEFT,wraplength=1000)

tkvar.trace('w', change_dropdown)
width, height = root.winfo_screenwidth(), root.winfo_screenheight()
root.geometry('%dx%d+0+0' % (width,height))

root.mainloop()


