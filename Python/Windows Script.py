import os 
print("1.Shutdown")
print("2.Retstart")
print("3.Exit")
n = input("What do you want ? \n")  
if n=='1': 
    os.system("shutdown /s /t 1") 
elif n=='2': 
    os.system("shutdown /r /t 1")
else:
    exit()
