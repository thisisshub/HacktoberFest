class Person:
    def __init__(self,initialAge):
        if initialAge < 0:
            age =0
            print("Age is not valid, setting age to 0.")
        else:
            age = initialAge
    def amIOld(self):
        if age < 13:
            print("You are young.")
        elif 13 <= age < 18:
            print("You are a teenager.")
        else:
            print("You are old.")
    def yearPasses(self):
        global age
        age += 1


t = int(input())
for i in range(0, t):
    age = int(input())
    p = Person(age)
    p.amIOld()
    for j in range(0, 3):
        p.yearPasses()
    p.amIOld()
    print("")