def gradingStudents(grades):
    for i in range(len(grades)):
        if grades[i]< 38:
            print(grades[i])
        else:
            if grades[i]%5 >= 3:
                print(5 * round(grades[i] / 5))

            else:
                print(grades[i])


if __name__ == '__main__':
    grades_count = int(input().strip())

    grades = []

    for _ in range(grades_count):
        grades_item = int(input().strip())
        grades.append(grades_item)

    gradingStudents(grades)