class Person:
    def __init__(self, firstName, lastName, idNumber):
        self.firstName = firstName
        self.lastName = lastName
        self.idNumber = idNumber

    def printPerson(self):
        print("Name:", self.lastName + ",", self.firstName)
        print("ID:", self.idNumber)


class Student(Person):
    def __init__(self,  firstName, lastName, idNumber, scores):
        Person.__init__(self, firstName, lastName, idNumber)
        self.scores = scores

    def calculate(self):
        sum =0
        for score in scores:
            sum+=score
        avg = sum/len(scores)
        if 90 <= avg <=100:
            return "O"
        if 80 <= avg <=90:
            return "E"
        if 70 <= avg <=80:
            return "A"
        if 55 <= avg <=70:
            return "P"
        if 40 <= avg <=55:
            return "D"
        if avg < 40:
            return "T"


line = input().split()
firstName = line[0]
lastName = line[1]
idNum = line[2]
numScores = int(input())  # not needed for Python
scores = list(map(int, input().split()))
s = Student(firstName, lastName, idNum, scores)
s.printPerson()
print("Grade:", s.calculate())