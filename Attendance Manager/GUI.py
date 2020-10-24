import sqlite3
import tkinter
import os
import datetime
from tkinter import messagebox as ms, ttk
from tkinter import *


class Graphics:
    def __init__(self):
        self.root = root

        self.now = datetime.datetime.now()
        self.date = str(self.now.day) + '-' + str(self.now.month) + '-' + str(self.now.year)

        self.no_total_student = 0
        self.no_present_student = 0
        self.no_absent_student = 0

        self.data_total_student = []
        self.data_absent_student = []
        self.data_present_student = []

        self.last_std_name = "None"
        self.last_std_roll_no = 00
        self.last_std_dob = "01-01-1973"
        self.last_std_contact_no = 9999999999
        self.last_std_father_name = "None"
        self.last_std_age = 20

        self.add_std_data = []

        self.name = StringVar()
        self.div = StringVar()
        self.contact = StringVar()
        self.roll = StringVar()
        self.year = StringVar()
        self.course = StringVar()
        self.dob = StringVar()
        self.gender = StringVar()
        self.father_name = StringVar()
        self.add_roll = StringVar()

        self.total_student_list = []
        self.present_student_list = []
        self.absent_student_list = []

        self.f_home = Frame
        self.f_task_frame = Frame
        self.f_student = Frame

        self.f_total_students = Frame
        self.f_absent_student = Frame
        self.f_present_student = Frame

        self.f_add_sheet = Frame
        self.f_manage_menu = Frame
        self.current_frame = Frame

        self.task_bar()
        self.attendance_label()

        self.bug_num = int
        self.flag_win_add_sheet = True
        self.tree_add_sheet = ttk
        self.tree_total_student = ttk
        self.tree_absent_student = ttk
        self.tree_present_student = ttk

        self.saveflag = True
        # self.win_add_sheet = Toplevel
        self.win_edit_sheet = Toplevel
        self.f_win_add_student = Toplevel
        self.win_delete_student = Toplevel

    def menu(self):
        pass

    def task_bar(self):
        with sqlite3.connect('./Database/database.db') as ddb:
            cur = ddb.cursor()

        find_students = 'SELECT * FROM students'
        cur.execute(find_students)
        students = cur.fetchall()

        if students:
            for student in students:
                self.no_total_student += 1
                self.data_total_student.append(student)
        else:
            self.no_total_student = 0

        # data = [self.last_std_name, self.last_std_roll_no, self.last_std_dob, self.last_std_contact_no,
        #  self.last_std_father_name, , self.last_std_age]

        table_name = str(self.date).replace('-', '')

        with sqlite3.connect('./Database/database.db') as ddb:
            cur = ddb.cursor()

        cur.execute('CREATE TABLE IF NOT EXISTS Table' + table_name + ' (name TEXT NOT NULL,'
                                                                      ' father_name TEXT, age INTEGER,'
                    ' roll_no INTEGER UNIQUE, dob TIMESTAMP, course TEXT, year INTEGER, div INTEGER,'
                    ' gender TEXT, contact LONG)')

        self.lable_manage()

        data = []
        self.f_task_frame = Frame(self.root, padx=30, pady=10)
        Button(self.f_task_frame, text="Home", font=('', 15), bd=2, padx=15, pady=15,
               command=self.attendance_label)\
            .grid(row=0, column=0, padx=5, pady=5)
        Button(self.f_task_frame, text="Add Sheet", font=('', 15), pady=10, padx=15,
               command=lambda: self.manage_add_sheet(data))\
            .grid(row=0, column=1, padx=5, pady=5)
        Button(self.f_task_frame, text="Add Student", font=('', 15), padx=15, pady=10,
               command=self.add_student) \
            .grid(row=0, column=2, padx=5, pady=5)
        Button(self.f_task_frame, text="Delete", font=('', 15), padx=15, pady=5,
               command=self.delete_student) \
               .grid(row=0, column=3, padx=5, pady=5)
        Button(self.f_task_frame, text="Close", font=('', 15), bd=2, padx=25, pady=15,
               command=lambda: self.root.destroy())\
            .grid(row=0, column=6, padx=(120, 0), pady=5)
        self.f_task_frame.pack(anchor=W)

    def attendance_label(self):
        self.lable_manage()
        self.forgot_packed()
        with sqlite3.connect('./Database/database.db') as ddb:
            cur = ddb.cursor()

        find_students = 'SELECT * FROM students'
        cur.execute(find_students)
        students = cur.fetchall()

        if students:
            for student in students:
                if student not in self.data_total_student:
                    self.no_total_student += 1
                    self.data_total_student.append(student)
        else:
            self.no_total_student = 0

        self.f_home = Frame(self.root, padx=10, pady=10)
        Label(self.f_home, text=str(self.no_total_student), font=("", 75))\
            .grid(row=0, column=0, padx=90, pady=(80, 20))
        Button(self.f_home, text="Total Students", font=("", 13), command=self.details_total_student)\
            .grid(row=1, column=0, padx=90)
        Label(self.f_home, text=str(self.no_present_student), font=("", 75)) \
            .grid(row=0, column=1, padx=90, pady=(80, 20))
        Button(self.f_home, text="Present Students", font=("", 13), command=self.details_present_student)\
            .grid(row=1, column=1, padx=90)
        Label(self.f_home, text=str(self.no_absent_student), font=("", 75)) \
            .grid(row=0, column=2, padx=90, pady=(80, 20))
        Label(self.f_home, text="Absent Students", font=("", 13))\
            .grid(row=1, column=2, padx=90)
        self.f_home.pack(anchor=W)
        self.current_frame = self.f_home

        db.close()

    def forgot_packed(self):
        try:
            self.current_frame.pack_forget()
        except TypeError:
            pass

    def details_total_student(self):
        self.forgot_packed()
        self.f_total_students = Frame(self.root, padx=10, pady=40)

        x_scrollbar = Scrollbar(self.f_total_students, orient=HORIZONTAL)
        x_scrollbar.pack(side=BOTTOM, fill='x')

        y_scrollbar = Scrollbar(self.f_total_students, orient=VERTICAL)
        y_scrollbar.pack(side=RIGHT, fill='y')

        self.tree_total_student = ttk.Treeview(self.f_total_students, column=(1, 2, 3, 4, 5, 6, 7, 8),
                                               height=40, show="headings",
                                               xscrollcommand=x_scrollbar.set,
                                               yscrollcommand=y_scrollbar.set)
        x_scrollbar.config(command=self.tree_total_student.xview)
        y_scrollbar.config(command=self.tree_total_student.yview)

        self.tree_total_student.pack(anchor='c')

        self.tree_total_student.heading(1, text="Roll No.")
        self.tree_total_student.heading(2, text="Name")
        self.tree_total_student.heading(3, text='Div')
        self.tree_total_student.heading(4, text='Year')
        self.tree_total_student.heading(5, text='Course')
        self.tree_total_student.heading(6, text="Contact")
        self.tree_total_student.heading(7, text='Date of Birth')
        self.tree_total_student.heading(8, text='Gender')

        self.tree_total_student.column(1, width=80, anchor='c')
        self.tree_total_student.column(2, width=300, anchor='c')
        self.tree_total_student.column(3, width=80, anchor='c')
        self.tree_total_student.column(4, width=80, anchor='c')
        self.tree_total_student.column(5, width=150, anchor='c')
        self.tree_total_student.column(6, width=150, anchor='c')
        self.tree_total_student.column(7, width=150, anchor='c')
        self.tree_total_student.column(8, width=50, anchor='c')

        for data in self.data_total_student:
            self.tree_total_student.insert('', 'end',
                                           values=(data[3], data[0],
                                                   data[7], data[6],
                                                   data[5], data[9],
                                                   data[4], data[8]))
        self.f_total_students.pack()
        self.current_frame = self.f_total_students

    def details_present_student(self):
        self.forgot_packed()
        self.f_present_student = Frame(self.root, padx=10, pady=10)

        x_scrollbar = Scrollbar(self.f_present_student, orient=HORIZONTAL)
        x_scrollbar.pack(side=BOTTOM, fill='x')

        y_scrollbar = Scrollbar(self.f_present_student, orient=VERTICAL)
        y_scrollbar.pack(side=RIGHT, fill='y')

        self.tree_present_student = ttk.Treeview(self.f_present_student, column=(1, 2, 3, 4, 5, 6, 7, 8),
                                                 height=40, show="headings",
                                                 xscrollcommand=x_scrollbar.set,
                                                 yscrollcommand=y_scrollbar.set)
        x_scrollbar.config(command=self.tree_present_student.xview)
        y_scrollbar.config(command=self.tree_present_student.yview)

        self.tree_present_student.pack(anchor='c')

        self.tree_present_student.heading(1, text="Roll No.")
        self.tree_present_student.heading(2, text="Name")
        self.tree_present_student.heading(3, text='Div')
        self.tree_present_student.heading(4, text='Year')
        self.tree_present_student.heading(5, text='Course')
        self.tree_present_student.heading(6, text="Contact")
        self.tree_present_student.heading(7, text='Date of Birth')
        self.tree_present_student.heading(8, text='Gender')

        self.tree_present_student.column(1, width=80, anchor='c')
        self.tree_present_student.column(2, width=300, anchor='c')
        self.tree_present_student.column(3, width=80, anchor='c')
        self.tree_present_student.column(4, width=80, anchor='c')
        self.tree_present_student.column(5, width=150, anchor='c')
        self.tree_present_student.column(6, width=150, anchor='c')
        self.tree_present_student.column(7, width=150, anchor='c')
        self.tree_present_student.column(8, width=50, anchor='c')

        for data in self.data_present_student:
            self.tree_present_student.insert('', 'end',
                                             values=(data[3], data[0],
                                                     data[7], data[6],
                                                     data[5], data[9],
                                                     data[4], data[8]))

        self.f_present_student.pack()
        self.current_frame = self.f_present_student

    def details_absent_student(self):
        self.forgot_packed()
        self.f_absent_student = Frame(self.root, padx=10, pady=10)

        x_scrollbar = Scrollbar(self.f_absent_student, orient=HORIZONTAL)
        x_scrollbar.pack(side=BOTTOM, fill='x')

        y_scrollbar = Scrollbar(self.f_absent_student, orient=VERTICAL)
        y_scrollbar.pack(side=RIGHT, fill='y')

        self.tree_absent_student = ttk.Treeview(self.f_absent_student, column=(1, 2, 3, 4, 5, 6, 7, 8),
                                                height=40, show="headings",
                                                xscrollcommand=x_scrollbar.set,
                                                yscrollcommand=y_scrollbar.set)
        x_scrollbar.config(command=self.tree_absent_student.xview)
        y_scrollbar.config(command=self.tree_absent_student.yview)

        self.tree_absent_student.pack(anchor='c')

        self.tree_absent_student.heading(1, text="Roll No.")
        self.tree_absent_student.heading(2, text="Name")
        self.tree_absent_student.heading(3, text='Div')
        self.tree_absent_student.heading(4, text='Year')
        self.tree_absent_student.heading(5, text='Course')
        self.tree_absent_student.heading(6, text="Contact")
        self.tree_absent_student.heading(7, text='Date of Birth')
        self.tree_absent_student.heading(8, text='Gender')

        self.tree_absent_student.column(1, width=80, anchor='c')
        self.tree_absent_student.column(2, width=300, anchor='c')
        self.tree_absent_student.column(3, width=80, anchor='c')
        self.tree_absent_student.column(4, width=80, anchor='c')
        self.tree_absent_student.column(5, width=150, anchor='c')
        self.tree_absent_student.column(6, width=150, anchor='c')
        self.tree_absent_student.column(7, width=150, anchor='c')
        self.tree_absent_student.column(8, width=50, anchor='c')

        for data in self.data_absent_student:
            self.tree_absent_student.insert('', 'end',
                                            values=(data[3], data[0],
                                                    data[7], data[6],
                                                    data[5], data[9],
                                                    data[4], data[8]))

        self.f_absent_student.pack()
        self.current_frame = self.f_absent_student

    # def manage(self):
    #     self.forgot_packed()
    #     self.f_manage_menu = Frame(self.root, padx=10, pady=10)
    #
    #     Button(self.f_manage_menu, text="Add Sheet", font=('', 15), pady=15, padx=30, command=self.manage_add_sheet)\
    #         .grid(row=0, column=0, padx=40, pady=80)
    #     Button(self.f_manage_menu, text="Edit Sheet", font=('', 15), padx=30, pady=15, command=self.manage_edit_sheet)\
    #         .grid(row=0, column=1, padx=40, pady=80)
    #
    #     self.f_manage_menu.pack()
    #     self.current_frame = self.f_manage_menu

    def manage_add_sheet(self, data):
        self.saveflag = False
        if self.current_frame != self.f_win_add_student:
            self.forgot_packed()
            self.f_win_add_student = Frame(self.root, padx=10)

            self.f_add_sheet = Frame(self.f_win_add_student, padx=0, pady=30)
            x_scrollbar = Scrollbar(self.f_add_sheet, orient=HORIZONTAL)
            x_scrollbar.pack(side=BOTTOM, fill='x')

            y_scrollbar = Scrollbar(self.f_add_sheet, orient=VERTICAL)
            y_scrollbar.pack(side=RIGHT, fill='y')

            self.tree_add_sheet = ttk.Treeview(self.f_add_sheet, column=(1, 2, 3, 4, 5, 6, 7, 8),
                                               height=26, show="headings",
                                               xscrollcommand=x_scrollbar.set,
                                               yscrollcommand=y_scrollbar.set)
            x_scrollbar.config(command=self.tree_add_sheet.xview)
            y_scrollbar.config(command=self.tree_add_sheet.yview)

            self.tree_add_sheet.pack(anchor='c')
            self.f_add_sheet.grid(row=8, column=0, sticky=W)

            self.tree_add_sheet.heading(1, text="Roll No.")
            self.tree_add_sheet.heading(2, text="Name")
            self.tree_add_sheet.heading(3, text='Div')
            self.tree_add_sheet.heading(4, text='Year')
            self.tree_add_sheet.heading(5, text='Course')
            self.tree_add_sheet.heading(6, text="Contact")
            self.tree_add_sheet.heading(7, text='Date of Birth')
            self.tree_add_sheet.heading(8, text='Gender')

            self.tree_add_sheet.column(1, width=80, anchor='c')
            self.tree_add_sheet.column(2, width=300, anchor='c')
            self.tree_add_sheet.column(3, width=80, anchor='c')
            self.tree_add_sheet.column(4, width=80, anchor='c')
            self.tree_add_sheet.column(5, width=150, anchor='c')
            self.tree_add_sheet.column(6, width=150, anchor='c')
            self.tree_add_sheet.column(7, width=150, anchor='c')
            self.tree_add_sheet.column(8, width=50, anchor='c')

        if data:
            self.last_std_name = data[0]
            self.last_std_roll_no = data[3]
            self.last_std_dob = data[4]
            self.last_std_contact_no = data[9]
            self.last_std_father_name = data[1]
            self.last_std_age = data[2]

            Label(self.f_win_add_student, text="Roll Number", font=('', 17), padx=10, pady=10) \
                .grid(row=0, padx=(500, 0), pady=(20, 0), sticky=W)
            Entry(self.f_win_add_student, bd=2, width=8, justify='center', textvariable=self.add_roll) \
                .grid(row=0, pady=(20, 0), padx=(620, 0), sticky=W)
            Button(self.f_win_add_student, text="Add", font=('', 15), padx=15, pady=5,
                   command=self.last_student_details) \
                .grid(row=0, pady=(20, 0), padx=(720, 0), sticky=W)

            Label(self.f_win_add_student, text="Last Student Details", font=('', 20), padx=10, pady=10) \
                .grid(row=1, padx=10, sticky=W)

            Label(self.f_win_add_student, text="Name:", font=('Helvetica 18 bold', 15), pady=10) \
                .grid(row=2, padx=35, sticky=W)
            Label(self.f_win_add_student, text=self.last_std_name, font=('', 13), pady=10) \
                .grid(row=2, padx=85, pady=2, sticky=W)

            Label(self.f_win_add_student, text="Roll No:", font=('Helvetica 18 bold', 15), pady=10) \
                .grid(row=3, padx=35, sticky=W)
            Label(self.f_win_add_student, text=self.last_std_roll_no, font=('', 13), pady=10, padx=5) \
                .grid(row=3, padx=100, pady=2, sticky=W)

            Label(self.f_win_add_student, text="Date Of Birth:", font=('Helvetica 18 bold', 15), pady=10) \
                .grid(row=2, padx=290, sticky=W)
            Label(self.f_win_add_student, text=self.last_std_dob, font=('', 13), pady=10, padx=10).grid(row=2, padx=390, pady=2,
                                                                                           sticky=W)

            Label(self.f_win_add_student, text="Contact No:", font=('Helvetica 18 bold', 15), pady=10) \
                .grid(row=3, padx=290, sticky=W)
            Label(self.f_win_add_student, text=self.last_std_contact_no, font=('', 13), pady=10, padx=10) \
                .grid(row=3, padx=390, pady=2, sticky=W)

            Label(self.f_win_add_student, text="Father's Name:", font=('Helvetica 18 bold', 15), pady=10) \
                .grid(row=2, padx=540, sticky=W)
            Label(self.f_win_add_student, text=self.last_std_father_name, font=('', 13), pady=10, padx=15) \
                .grid(row=2, padx=650, pady=2, sticky=W)

            Label(self.f_win_add_student, text="Age:", font=('Helvetica 18 bold', 15), pady=10) \
                .grid(row=3, padx=540, sticky=W)
            Label(self.f_win_add_student, text=self.last_std_age, font=('', 13), pady=10) \
                .grid(row=3, padx=590, pady=2, sticky=W)

            self.tree_add_sheet.insert('', 'end',
                                       values=(data[3], data[0],
                                               data[7], data[6],
                                               data[5], data[9],
                                               data[4], data[8]))
            self.present_student_list.append(data)
            self.add_roll.set("")
        else:
            self.last_std_name = "None"
            self.last_std_roll_no = 00
            self.last_std_dob = "01-01-1973"
            self.last_std_contact_no = 9999999999
            self.last_std_father_name = "None"
            self.last_std_age = 20

            Label(self.f_win_add_student, text="Roll Number", font=('', 17), padx=10, pady=10) \
                .grid(row=0, padx=(500, 0), pady=(20, 0), sticky=W)
            Entry(self.f_win_add_student, bd=2, width=8, justify='center', textvariable=self.add_roll) \
                .grid(row=0, pady=(20, 0), padx=(620, 0), sticky=W)
            Button(self.f_win_add_student, text="Add", font=('', 15), padx=15, pady=5,
                   command=self.last_student_details) \
                .grid(row=0, pady=(20, 0), padx=(720, 0), sticky=W)

            Button(self.f_win_add_student, text="Save", font=('', 15), padx=15, pady=5,
                   command=lambda: self.save_student_attendance(self.present_student_list)) \
                .grid(row=0, pady=(20, 0), padx=(800, 0), sticky=W)

            Label(self.f_win_add_student, text="Last Student Details", font=('', 20), padx=10, pady=10) \
                .grid(row=1, padx=10, sticky=W)

            Label(self.f_win_add_student, text="Name:", font=('Helvetica 18 bold', 15), pady=10) \
                .grid(row=2, padx=35, sticky=W)
            Label(self.f_win_add_student, text=self.last_std_name, font=('', 13), pady=10) \
                .grid(row=2, padx=85, pady=2, sticky=W)

            Label(self.f_win_add_student, text="Roll No:", font=('Helvetica 18 bold', 15), pady=10) \
                .grid(row=3, padx=35, sticky=W)
            Label(self.f_win_add_student, text=self.last_std_roll_no, font=('', 13), pady=10) \
                .grid(row=3, padx=100, pady=2, sticky=W)

            Label(self.f_win_add_student, text="Date Of Birth:", font=('Helvetica 18 bold', 15), pady=10) \
                .grid(row=2, padx=290, sticky=W)
            Label(self.f_win_add_student, text=self.last_std_dob, font=('', 13), pady=10).grid(row=2, padx=390, pady=2,
                                                                                           sticky=W)

            Label(self.f_win_add_student, text="Contact No:", font=('Helvetica 18 bold', 15), pady=10) \
                .grid(row=3, padx=290, sticky=W)
            Label(self.f_win_add_student, text=self.last_std_contact_no, font=('', 13), pady=10) \
                .grid(row=3, padx=390, pady=2, sticky=W)

            Label(self.f_win_add_student, text="Father's Name:", font=('Helvetica 18 bold', 15), pady=10) \
                .grid(row=2, padx=540, sticky=W)
            Label(self.f_win_add_student, text=self.last_std_father_name, font=('', 13), pady=10) \
                .grid(row=2, padx=650, pady=2, sticky=W)

            Label(self.f_win_add_student, text="Age:", font=('Helvetica 18 bold', 15), pady=10) \
                .grid(row=3, padx=540, sticky=W)
            Label(self.f_win_add_student, text=self.last_std_age, font=('', 13), pady=10) \
                .grid(row=3, padx=590, pady=2, sticky=W)

            self.f_add_sheet = Frame(self.f_win_add_student, padx=0, pady=30)
            x_scrollbar = Scrollbar(self.f_add_sheet, orient=HORIZONTAL)
            x_scrollbar.pack(side=BOTTOM, fill='x')

            y_scrollbar = Scrollbar(self.f_add_sheet, orient=VERTICAL)
            y_scrollbar.pack(side=RIGHT, fill='y')

            self.tree_add_sheet = ttk.Treeview(self.f_add_sheet, column=(1, 2, 3, 4, 5, 6, 7, 8),
                                               height=26, show="headings",
                                               xscrollcommand=x_scrollbar.set,
                                               yscrollcommand=y_scrollbar.set)
            x_scrollbar.config(command=self.tree_add_sheet.xview)
            y_scrollbar.config(command=self.tree_add_sheet.yview)

            self.tree_add_sheet.pack_forget()
            self.tree_add_sheet.pack(anchor='c')
            self.f_add_sheet.grid(row=8, column=0, sticky=W)

            self.tree_add_sheet.heading(1, text="Roll No.")
            self.tree_add_sheet.heading(2, text="Name")
            self.tree_add_sheet.heading(3, text='Div')
            self.tree_add_sheet.heading(4, text='Year')
            self.tree_add_sheet.heading(5, text='Course')
            self.tree_add_sheet.heading(6, text="Contact")
            self.tree_add_sheet.heading(7, text='Date of Birth')
            self.tree_add_sheet.heading(8, text='Gender')

            self.tree_add_sheet.column(1, width=80, anchor='c')
            self.tree_add_sheet.column(2, width=300, anchor='c')
            self.tree_add_sheet.column(3, width=80, anchor='c')
            self.tree_add_sheet.column(4, width=80, anchor='c')
            self.tree_add_sheet.column(5, width=150, anchor='c')
            self.tree_add_sheet.column(6, width=150, anchor='c')
            self.tree_add_sheet.column(7, width=150, anchor='c')
            self.tree_add_sheet.column(8, width=50, anchor='c')

        self.f_win_add_student.pack()
        self.current_frame = self.f_win_add_student

    def delete_student_attendance(self):
        del_std_roll = self.add_roll.get()
        with sqlite3.connect('./Database/database.db') as ddb:
            cur = ddb.cursor()

        find_students = 'DELETE FROM students where roll_no=?'
        cur.execute(find_students, [del_std_roll])
        ddb.commit()
        ddb.close()

    def last_student_details(self):
        self.saveflag = False
        with sqlite3.connect('./Database/database.db') as ddb:
            cur = ddb.cursor()

        find_students = 'SELECT * FROM students where roll_no=?'
        cur.execute(find_students, [self.add_roll.get()])
        students = cur.fetchone()
        if students:
            self.manage_add_sheet(students)
        else:
            ms.showerror("Oops", "Student Doesn't exist!")
            self.add_roll.set("")

    def add_student(self):
        self.win_add_student = Toplevel(self.root)
        self.win_add_student.geometry('840x700+300+80')
        self.win_add_student.title("ADD STUDENT")

        self.f_win_add_student = Frame(self.win_add_student, padx=10, pady=10)

        Label(self.f_win_add_student, text="Name", font=('', 17))\
            .grid(row=0, column=0, padx=(80, 0), pady=(50, 0))
        Entry(self.f_win_add_student, width=25, textvariable=self.name)\
            .grid(row=1, column=0, padx=(80, 0), pady=(10, 0))

        Label(self.f_win_add_student, text="Div No.", font=('', 17))\
            .grid(row=0, column=1, padx=(80, 0), pady=(50, 0))
        Entry(self.f_win_add_student, width=5, justify="center", textvariable=self.div)\
            .grid(row=1, column=1, padx=(80, 0), pady=(10, 0))

        Label(self.f_win_add_student, text="Contact No.", font=('', 17))\
            .grid(row=0, column=2, padx=(80, 0), pady=(50, 0))
        Entry(self.f_win_add_student, width=15, justify="center", textvariable=self.contact)\
            .grid(row=1, column=2, padx=(80, 0), pady=(10, 0))

        Label(self.f_win_add_student, text="Roll No.", font=('', 17)) \
            .grid(row=2, column=0, padx=(80, 0), pady=(50, 0))
        Entry(self.f_win_add_student, width=8, justify="center", textvariable=self.roll) \
            .grid(row=3, column=0, padx=(80, 0), pady=(10, 0))

        Label(self.f_win_add_student, text="Year", font=('', 17)) \
            .grid(row=2, column=1, padx=(80, 0), pady=(50, 0))
        Entry(self.f_win_add_student, width=5, justify="center", textvariable=self.year) \
            .grid(row=3, column=1, padx=(80, 0), pady=(10, 0))

        Label(self.f_win_add_student, text="Course", font=('', 17)) \
            .grid(row=2, column=2, padx=(80, 0), pady=(50, 0))
        Entry(self.f_win_add_student, width=12, justify="center", textvariable=self.course) \
            .grid(row=3, column=2, padx=(80, 0), pady=(10, 0))

        Label(self.f_win_add_student, text="Date of Birth", font=('', 17)) \
            .grid(row=4, column=0, padx=(80, 0), pady=(50, 0))
        Entry(self.f_win_add_student, width=8, justify="center", textvariable=self.dob) \
            .grid(row=5, column=0, padx=(80, 0), pady=(10, 0))

        Label(self.f_win_add_student, text="Gender", font=('', 17)) \
            .grid(row=4, column=1, padx=(80, 0), pady=(50, 0))
        Entry(self.f_win_add_student, width=5, justify="center", textvariable=self.gender) \
            .grid(row=5, column=1, padx=(80, 0), pady=(10, 0))

        Label(self.f_win_add_student, text="Father Name", font=('', 17)) \
            .grid(row=4, column=2, padx=(80, 0), pady=(50, 0))
        Entry(self.f_win_add_student, width=15, justify="center", textvariable=self.father_name) \
            .grid(row=5, column=2, padx=(80, 0), pady=(10, 0))

        Button(self.f_win_add_student, text="SAVE", pady=15, padx=15, command=self.add_student_validator)\
            .grid(row=7, column=1, pady=50)
        Button(self.f_win_add_student, text="DONE", pady=15, padx=15, command=self.win_add_student.destroy)\
            .grid(row=7, column=2, pady=50)

        self.f_win_add_student.pack()

    def add_student_validator(self):
        dob_year = 1998
        data = [self.name.get(), self.father_name.get(),
                self.now.year - dob_year, self.roll.get(), self.dob.get(),
                self.course.get(), self.year.get(), self.div.get(),
                self.gender.get(), self.contact.get()]
        # print(data)
        self.db_add_student(data)

    def db_add_student(self, data):
        with sqlite3.connect('./Database/database.db') as ddb:
            cur = ddb.cursor()

        try:
            insert_report = ('INSERT INTO students (name, father_name, age, '
                             'roll_no, dob, course, year, div,'
                             ' gender, contact) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)')
            cur.execute(insert_report, [str(data[0]), str(data[1]), int(data[2]), int(data[3]),
                                        str(data[4]), str(data[5]), int(data[6]), int(data[7]),
                                        str(data[8]), str(data[9])])

            ms.showerror("Done", "Student Added")
            ddb.commit()
            ddb.close()
        except sqlite3.IntegrityError:
            ms.showerror("Oops", "Student with same roll no already exist")

    def save_student_attendance(self, add_std_data):

        self.data_present_student = add_std_data
        self.no_present_student = len(self.data_present_student)

        table_name = str(self.date).replace('-', '')

        with sqlite3.connect('./Database/database.db') as ddb:
            cur = ddb.cursor()

        for data in add_std_data:
            insert_attendance = ('INSERT INTO Table' + table_name + ' (name, father_name, age, '
                                 'roll_no, dob, course, year, div,'
                                 ' gender, contact) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)')
            cur.execute(insert_attendance, [str(data[0]), str(data[1]), int(data[2]), int(data[3]),
                                            str(data[4]), str(data[5]), int(data[6]), int(data[7]),
                                            str(data[8]), str(data[9])])

        self.lable_manage()

        ddb.commit()
        ddb.close()

    def lable_manage(self):
        table_name = str(self.date).replace('-', '')

        with sqlite3.connect('./Database/database.db') as ddb:
            cur = ddb.cursor()
        que1 = 'SELECT * FROM students'
        cur.execute(que1)
        self.total_student_list = cur.fetchall()
        self.no_total_student = len(self.total_student_list)

        que2 = 'SELECT * FROM Table' + table_name
        cur.execute(que2)
        self.present_student_list = cur.fetchall()
        self.no_present_student = len(self.present_student_list)
        self.no_absent_student = self.no_total_student - self.no_present_student

    def view_student(self):
        if self.current_frame != self.f_view_student:
            self.forgot_packed()

        self.f_view_student = Frame(self.root, padx=10, pady=10)
        self.f_view_student.pack()
        self.current_frame = self.f_view_student

    def delete_student(self):
        self.delete_std_roll = StringVar()
        self.win_delete_student = Toplevel()
        self.win_delete_student.geometry('380x120+100+240')
        self.win_delete_student.title("Delete Student")

        self.f_delet_std = Frame(self.win_delete_student, padx=10, pady=10)
        Label(self.f_delet_std, text="Roll No: ", padx=10).grid(row=0, column=0)
        Entry(self.f_delet_std, textvariable=self.delete_std_roll, width=5).grid(row=0, column=1)
        Button(self.f_delet_std, text="Delete", padx=10, pady=8, command=lambda: self.delete_student_logic(self.delete_std_roll.get()))\
            .grid(row=1, column=0)
        Button(self.f_delet_std, text="Done", padx=10, pady=8, command=self.win_delete_student.destroy) \
            .grid(row=1, column=1, padx=20)
        self.f_delet_std.pack()

    def delete_student_logic(self, roll):
        with sqlite3.connect('./Database/database.db') as db:
            c = db.cursor()
        c.execute('DELETE FROM students WHERE roll_no = ?', [roll])
        db.commit()
        db.close()
        ms.showerror("Done", "Student deleted Successfully!")


if __name__ == "__main__":

    if os.path.isdir('./Database'):
        pass
    else:
        os.mkdir('./Database')

    with sqlite3.connect('./Database/database.db') as db:
        c = db.cursor()

    c.execute('CREATE TABLE IF NOT EXISTS students (name TEXT NOT NULL, father_name TEXT, age INTEGER,'
              ' roll_no INTEGER UNIQUE, dob TIMESTAMP, course TEXT, year INTEGER, div INTEGER,'
              ' gender TEXT, contact LONG)')

    db.commit()
    db.close()

    root = tkinter.Tk()
    f = Graphics()
    root.geometry('1000x900+240+80')
    root.title("Attendance Monitor")
    root.mainloop()
