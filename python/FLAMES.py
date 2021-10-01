
import string
p1=input("Enter first person name:")
p1=p1.lower()
p1=p1.replace(" ","")

p2=input("Enter second person name:")
p2=p2.lower()
p2=p2.replace(" ","")

p="".join(set(p1+p2))
count=len(p)
result=['Friends','Love','Affection','Marriage','Enemy','Siblings']
t=count%7
print(result[t]) 
