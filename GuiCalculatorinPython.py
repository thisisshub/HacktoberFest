#Making a GUI in python, using its Tkinter library
#Tkinter is python's de-facto GUI library

from tkinter import *
import math

root = Tk()
root.title('Calculator App')


#Grid Layout being used in whole application
answerVariableGlobal =""
answerLabelforSquareRoot = ""

answerEntryLabel = StringVar()
Label(root, font =  ('helvetica',25,'bold'),textvariable = answerEntryLabel, justify = LEFT, height = 2, width = 20,bg ="white",borderwidth=2, relief="sunken").grid(columnspan = 4)

answerFinalLabel = StringVar()
Label(root, font =  ('helvetica',25,'bold'),textvariable = answerFinalLabel, justify = LEFT, height = 2, width = 20,bg = "white", borderwidth=2, relief="sunken").grid(columnspan = 4) 


def changeAnswerEntryLabel(entry):
    global answerVariableGlobal
    global answerLabelforSquareRoot
    answerVariableGlobal = answerVariableGlobal + str(entry)
    answerLabelforSquareRoot = answerVariableGlobal
    answerEntryLabel.set(answerVariableGlobal)

def allClear():
    global answerVariableGlobal
    global answerLabelforSquareRoot
    answerVariableGlobal = ""
    answerLabelforSquareRoot = ""
    answerEntryLabel.set("")
    answerFinalLabel.set("")

def clearAnswerEntryLabel():
    #clears the answerEntryLabel and also clears answerVariableGlobal
    global answerVariableGlobal
    global answerLabelForSquareRoot
    answerLabelForSquareRoot = answerVariableGlobal
    answerVariableGlobal = ""
    answerEntryLabel.set(answerVariableGlobal)


def evaluateSquareRoot():
    #evaluateSquareRoot - evaluates the expression present in
    #the answerLabelForSquareRoot for square root of that value and 
    #returns that value to answerFinalLabel

    global answerVariableGlobal
    global answerLabelforSquareRoot
    #answerLabelforSquareRoot = answerVariableGlobal
    try:

        sqrtAnswer = math.sqrt(eval(str(answerLabelforSquareRoot)))
        print(answerVariableGlobal,answerLabelforSquareRoot)
        #clearAnswerEntryLabel()
        changeAnswerEntryLabel("√")
        answerFinalLabel.set(sqrtAnswer)
    except(ValueError,SyntaxError,TypeError, ZeroDivisionError):
        try:
            sqrtAnswer = math.sqrt(eval(str(answerVariableGlobal)))
            clearAnswerEntryLabel()
            answerFinalLabel.set(sqrtAnswer)
        except(ValueError,SyntaxError,TypeError, ZeroDivisionError):#ErrorHandling
            clearAnswerEntryLabel()
            answerFinalLabel.set("Error!")




def evaluateAnswer():
    global answerVariableGlobal
    try:
        eval(answerVariableGlobal)
        evaluatedValueAnswerLabelGlobal = str(eval(answerVariableGlobal))
        answerFinalLabel.set(evaluatedValueAnswerLabelGlobal)
        #clearAnswerEntryLabel()
    except(ValueError,SyntaxError,TypeError, ZeroDivisionError):#ErrorHandling
        clearAnswerEntryLabel()
        answerFinalLabel.set("Error!")


#Creating buttons using a loop, could be hard coded also
def create_button(txt,x,y):
    Button(root,font = ('helvetica',25,'bold'),padx = 8, pady = 8, text = str(txt),
        command = lambda:changeAnswerEntryLabel(str(txt)),
        height = 2, width = 5).grid(row = x, column = y, sticky = E)

buttons = ['AC','√','%','/','7','8','9','*','4','5','6','-','1','2','3','+','','','.','c']
buttonsListTraversalCounter = 0

for i in range(3,8):
    for j in range(0,4):
        create_button(buttons[buttonsListTraversalCounter],i,j)
        buttonsListTraversalCounter = buttonsListTraversalCounter + 1

#rest of the buttons need to be hard coded with their own lambda functions
Button(root,font = ('helvetica',25,'bold'),padx = 8, pady = 8, text = "AC",
        command = lambda:allClear(),
        height = 2, width = 5).grid(row = 3, column = 0, sticky = E)

Button(root,font = ('helvetica',25,'bold'),padx = 8, pady = 8, text = "√",
        command = lambda:evaluateSquareRoot(),
        height = 2, width = 5).grid(row = 3, column = 1, sticky = E)

Button(root,font = ('helvetica',25,'bold'),padx = 8, pady = 8, text = "0",
        command = lambda:changeAnswerEntryLabel(str(0)),
        height = 2, width = 10).grid(row = 7, column = 0, columnspan = 2,sticky = E)

Button(root,font = ('helvetica',25,'bold'),padx = 8, pady = 8, text = "=",
        command = lambda:evaluateAnswer(),
        height = 2, width = 5).grid(row = 7, column = 3, sticky = E)


root.mainloop()
