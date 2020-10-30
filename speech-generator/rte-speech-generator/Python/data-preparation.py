import tensorflow as tf
import pandas as pd
import numpy as np
import nltk
import os
from keras.preprocessing import sequence
from nltk.corpus import stopwords
from textblob import TextBlob
from textblob import Word
from nltk.stem import PorterStemmer

nltk.download("wordnet")
nltk.download("stopwords")
nltk.download("punkt")
nltk.download("wordnet")

dosya_yolu = tf.keras.utils.get_file('rte-speech-generator-data.txt', 'https://raw.githubusercontent.com/ardauzunoglu/rte-speech-generator/master/rte-speech-generator/Text%20Files/rte-speech-generator-data.txt')

##dosyayı oku ve utf-8'e dönüştür
yazi = open(dosya_yolu, 'rb').read().decode(encoding = "utf-8")

##yazıyı satır boşluklarına göre böl
yazi1 = yazi.split("\n")
yaziSerisi = pd.Series(yazi1)
yaziFrame = pd.DataFrame(yaziSerisi, columns = ["cumleler"])

yazi2 = yaziFrame.copy()

yazi4 = yazi2["cumleler"].apply(lambda x: " ".join(x for x in x.split()))

sw = stopwords.words("turkish")

##stopwordleri (Türkçe'de sık kullanılan ve yazının yorumlanmasını zorlaştıran kelimeler) siliyoruz
yaziFrame3 = pd.DataFrame(yazi4, columns = ["cumleler"])
yazi6 = yaziFrame3["cumleler"].apply(lambda x: " ".join(x for x in x.split() if x not in sw))
yaziFrame4 = pd.DataFrame(yazi6, columns = ["cumleler"])

##boş kalan satırları siliyoruz
yaziFrame4['cumleler'].replace('', np.nan, inplace=True)
yaziFrame4.dropna(subset=['cumleler'], inplace=True)


##en az kullanılan 80000 kelimeyi (4 ve 4'ten az geçen kelimelere tekabül ediyor) siliyoruz
sil = pd.Series(" ".join(yaziFrame4["cumleler"]).split()).value_counts()[-80000:]
yazi7 = yaziFrame4["cumleler"].apply(lambda x: " ".join(x for x in x.split() if x not in sil))
yaziFrame5 = pd.DataFrame(yazi7, columns = ["cumleler"])

##bazı kelimeleri eklerinden ayırıyoruz
yaziFrame5["cumleler"].apply(lambda x: " ".join([Word(word).lemmatize() for word in x.split()]))

##indexleri düzeltiyoruz
indx = np.arange(1, len(yaziFrame5)+1)
yaziFrame5.set_index([indx])

##prepared-data.txt dosyasını oluşturuyoruz
yaziX = open("prepared-data.txt", "w")

for i in yaziFrame5["cumleler"]:

  ##cümleleri prepared-data.txt dosyasına yazıyoruz
  yaziX.write(i)
  yaziX.write("\n")

yaziX.close