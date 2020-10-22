#!/usr/bin/env python
# coding: utf-8

# Link to the dataset - https://data-flair.training/blogs/download-face-mask-detector-project-source-code/

# In[1]:


import tensorflow as tf
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPool2D, Flatten, Dense, Dropout
import numpy as np


# In[2]:


train_datagen = ImageDataGenerator(rescale=1.0/255,
                                  rotation_range=40,
                                  width_shift_range=0.2,
                                  height_shift_range=0.2,
                                  shear_range=0.2,
                                  zoom_range=0.2,
                                  horizontal_flip=True,
                                  fill_mode='nearest')

train_generator = train_datagen.flow_from_directory('./Dataset/train/train',
                                                   batch_size=10,
                                                   target_size=(150,150))

validation_datagen = ImageDataGenerator(rescale=1.0/255)
validation_generator = validation_datagen.flow_from_directory('./Dataset/test/test',
                                                             batch_size=10,
                                                             target_size=(150,150))


# In[3]:


model = Sequential()


# In[4]:


model.add(Conv2D(100, 3, activation='relu', input_shape=[150,150,3]))


# In[5]:


model.add(MaxPool2D((2,2)))


# In[6]:


model.add(Conv2D(100, 3, activation='relu'))


# In[7]:


model.add(MaxPool2D((2,2)))


# In[8]:


model.add(Flatten())


# In[9]:


model.add(Dropout(0.5))


# In[10]:


model.add(Dense(50, activation='relu'))


# In[11]:


model.add(Dense(2, activation='softmax'))


# In[12]:


model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])


# In[13]:


model.fit(train_generator,epochs=8,validation_data = validation_generator)


# In[ ]:


model.save('model.h5')


# In[ ]:


train_generator.class_indices





