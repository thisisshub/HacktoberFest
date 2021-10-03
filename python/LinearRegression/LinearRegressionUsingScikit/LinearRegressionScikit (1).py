#!/usr/bin/env python
# coding: utf-8

# In[78]:


import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


# In[79]:


dataset=pd.read_csv('Weight_and_Height1.csv')


# In[80]:


x=dataset.iloc[:,:-1].values
y=dataset.iloc[:, -1].values


# In[81]:


dataset.describe()


# In[82]:


dataset.head()


# In[83]:


dataset.info()


# In[84]:


# visualizing the data
plt.figure(figsize=(20,12))
sns.lineplot(data=dataset,x="Weight (kg)",y="Standing Height (cm)")
plt.show


# In[85]:


#creating a linear regression model and fit it using existing data
regressor=LinearRegression()
regressor.fit(x,y)
y_predict=list(regressor.predict(x))
#printing value of intercept and slope
print('intercept:',model.intercept_)
print('slope:',model.coef_)


# In[86]:


#predictions
y_predict[:5]


# In[88]:


plt.scatter(x,y,color='blue')
plt.plot(x,y_predict,color='red')
plt.xlabel('weight(kg)')
plt.ylabel('Standing Height (cm))')
plt.show()


# In[89]:


#r2_score
r2_score(y,y_predict)


# In[ ]:




