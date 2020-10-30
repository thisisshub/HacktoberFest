from keras.models import Sequential
from keras.layers import Dense,LSTM,Embedding
from keras.preprocessing.text import Tokenizer
from keras.utils import to_categorical
import numpy as np
data='rain rain go away come again some another day little johny wants to play. johny wants to play again in rain.'
tokenizer=Tokenizer()
tokenizer.fit_on_texts([data])
sequence=tokenizer.texts_to_sequences([data])[0]
tokens=(len(tokenizer.word_index))+1
sequences=[]
for i in range(1,len(sequence)):
    seq=sequence[i-1: i+1]
    #print(seq)
    sequences.append(seq)
sequences=np.array(sequences)
train_x,train_y=sequences[:,0],sequences[:,1]
train_y=to_categorical(train_y,num_classes=tokens)
model=Sequential()
model.add(Embedding(tokens,10,input_length=1))
model.add(LSTM(32))
model.add(Dense(tokens,activation='softmax'))
model.summary()
model.compile(loss='categorical_crossentropy',optimizer='adam',metrics=['accuracy'])
model.fit(train_x,train_y,epochs=500,verbose=1)

def generate_text(input_text):
    result=input_text
    
    for j in range(4):
        
        
        seq=np.array(tokenizer.texts_to_sequences([input_text])[0])
        pred_seq=model.predict_classes(seq)
        
        for word,index in tokenizer.word_index.items():
            if index==pred_seq:
                out_word=word
                break
        
        input_text=out_word
        result+=" "+out_word
    
    return result


generate_text('johny')
