from tkinter import *
import tkinter.messagebox

tk = Tk()
tk.title("Tic Tac Toe")

pa = StringVar()
playerb = StringVar()
p1 = StringVar()
p2 = StringVar()

player1_name = Entry(tk, textvariable=p1, bd=5)
player1_name.grid(row=1, column=1, columnspan=8)
player2_name = Entry(tk, textvariable=p2, bd=5)
player2_name.grid(row=2, column=1, columnspan=8)

bclick = True
flag = 0


def disableButton():
    button1.configure(state=DISABLED)
    button2.configure(state=DISABLED)
    button3.configure(state=DISABLED)
    button4.configure(state=DISABLED)
    button5.configure(state=DISABLED)
    button6.configure(state=DISABLED)
    button7.configure(state=DISABLED)
    button8.configure(state=DISABLED)
    button9.configure(state=DISABLED)


def btnclick(buttons):
    global bclick, flag, player2_name, player1_name, playerb, pa
    if buttons['text'] == " " and bclick == True:
        buttons['text'] = "X"
        bclick = False
        playerb = p2.get() + " Wins!"
        pa = p1.get() + " Wins!"
        checkForWin()
        flag += 1
    elif buttons['text'] == " " and bclick == False:
        buttons['text'] = "O"
        bclick = True
        checkForWin()
        flag += 1
    else:
        tkinter.messagebox.showinfo("Tic-Tac-Toe", "Button Already Clicked")


def checkForWin():
    if (button1['text'] == 'X' and button2['text'] == 'X' and button3['text'] == 'X' or
            button4['text'] == 'X' and button5['text'] == 'X' and button6['text'] == 'X' or
            button7['text'] == 'X' and button8['text'] == 'X' and button9['text'] == 'X' or
            button1['text'] == 'X' and button5['text'] == 'X' and button9['text'] == 'X' or
            button3['text'] == 'X' and button5['text'] == 'X' and button7['text'] == 'X' or
            button1['text'] == 'X' and button2['text'] == 'X' and button3['text'] == 'X' or
            button1['text'] == 'X' and button4['text'] == 'X' and button7['text'] == 'X' or
            button2['text'] == 'X' and button5['text'] == 'X' and button8['text'] == 'X' or
            button7['text'] == 'X' and button6['text'] == 'X' and button9['text'] == 'X' or
            button3['text'] == 'X' and button6['text'] == 'X' and button9['text'] == 'X'):
        disableButton()
        tkinter.messagebox.showinfo("Tic-Tac-Toe", pa)
    elif flag == 8:
        tkinter.messagebox.showinfo("Tic-Tac-Toe", "It is a Tie")
    elif (button1['text'] == 'O' and button2['text'] == 'O' and button3['text'] == 'O' or
          button4['text'] == 'O' and button5['text'] == 'O' and button6['text'] == 'O' or
          button7['text'] == 'O' and button8['text'] == 'O' and button9['text'] == 'O' or
          button1['text'] == 'O' and button5['text'] == 'O' and button9['text'] == 'O' or
          button3['text'] == 'O' and button5['text'] == 'O' and button7['text'] == 'O' or
          button1['text'] == 'O' and button2['text'] == 'O' and button3['text'] == 'O' or
          button1['text'] == 'O' and button4['text'] == 'O' and button7['text'] == 'O' or
          button2['text'] == 'O' and button5['text'] == 'O' and button8['text'] == 'O' or
          button7['text'] == 'O' and button6['text'] == 'O' and button9['text'] == 'O'):
        disableButton()
        tkinter.messagebox.showinfo("Tic-Tac-Toe", playerb)


buttons = StringVar()
label = Label(tk, text="Player 1:", font='Times 20 bold', bg="white", fg="black", width=6, height=4)
label.grid(row=1, column=0)

label1 = Label(tk, text="Player 2:", font='Times 20 bold', bg="white", fg="black", width=6, height=4)
label1.grid(row=2, column=0)
button1 = Button(tk, text=" ", font='Times 20 bold', bg="grey", fg="white", height=4, width=8,
                 command=lambda: btnclick(button1))
button1.grid(row=3, column=0)

button2 = Button(tk, text=" ", font='Times 20 bold', bg="grey", fg="white", height=4, width=8,
                 command=lambda: btnclick(button2))
button2.grid(row=3, column=1)

button3 = Button(tk, text=" ", font='Times 20 bold', bg="grey", fg="white", height=4, width=8,
                 command=lambda: btnclick(button3))
button3.grid(row=3, column=2)

button4 = Button(tk, text=" ", font='Times 20 bold', bg="grey", fg="white", height=4, width=8,
                 command=lambda: btnclick(button4))
button4.grid(row=4, column=0)

button5 = Button(tk, text=" ", font='Times 20 bold', bg="grey", fg="white", height=4, width=8,
                 command=lambda: btnclick(button5))
button5.grid(row=4, column=1)

button6 = Button(tk, text=" ", font='Times 20 bold', bg="grey", fg="white", height=4, width=8,
                 command=lambda: btnclick(button6))
button6.grid(row=4, column=2)

button7 = Button(tk, text=" ", font='Times 20 bold', bg="grey", fg="white", height=4, width=8,
                 command=lambda: btnclick(button7))
button7.grid(row=5, column=0)

button8 = Button(tk, text=" ", font='Times 20 bold', bg="grey", fg="white", height=4, width=8,
                 command=lambda: btnclick(button8))
button8.grid(row=5, column=1)

button9 = Button(tk, text=" ", font='Times 20 bold', bg="grey", fg="white", height=4, width=8,
                 command=lambda: btnclick(button9))
button9.grid(row=5, column=2)

tk.mainloop()
