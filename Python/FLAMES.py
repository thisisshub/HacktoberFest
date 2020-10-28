# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 10:29:10 2019

@author: SHAKESPEARE
"""

import string

def remove_matching_letter(l1,l2):
    for i in range(len(l1)):
        for j in range(len(l2)):
            if l1[i]==l2[j]:
                c=l1[i]
                l1.remove(c)
                l2.remove(c)
                l=l1+['*']+l2
                return [l,True]
    l=l1+['*']+l2
    return [l,False]

p1=input("Enter first person name:")
p1=p1.lower()
p1=p1.replace(" ","")

p2=input("Enter second person name:")
p2=p2.lower()
p2=p2.replace(" ","")

l1=list(p1)
l2=list(p2)
proceed=True
while proceed:
    ret_list=remove_matching_letter(l1,l2)
    con_list=ret_list[0]
    proceed=con_list[1]
    star_index=con_list.index('*')
    l1=con_list[:star_index]
    l2=con_list[star_index+1:]
    
count=len(l1)+len(l2)
result=['Friends','Love','Affection','Marriage','Enemy','Siblings']

while len(result)>1:
    split_index=(count%len(result))-1
    if split_index>=0:
        right=result[split_index+1:]
        left=result[:split_index]
        result=right+left
    else:
        result=result[:len(result)-1]
        
print(result[0])