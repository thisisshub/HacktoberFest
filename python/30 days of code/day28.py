import re


def solve(fname,email):
    new_fname = []
    for i in range(len(email)):
        if re.search("@gmail.com", email[i]):
            new_fname.append(fname[i])
    new_fname.sort()
    for i in range(0,len(new_fname)):
        print(new_fname[i])


if __name__ == '__main__':
    N = int(input())
    fname = []
    email = []

    for N_itr in range(N):
        firstNameEmailID = input().split()

        firstName = firstNameEmailID[0]
        fname.append(firstName)

        emailID = firstNameEmailID[1]
        email.append(emailID)
    solve(fname,email)