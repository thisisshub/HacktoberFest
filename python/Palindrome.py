example=input("Give input: ")
def pal(example):
    b=example[::-1]
    if example==b:
        return "True"
    return "false"
print(pal(example))