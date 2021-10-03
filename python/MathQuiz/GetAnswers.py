import requests
from bs4 import BeautifulSoup
import os
import io


def clear():
    if os.name == "posix":
        os.system('clear')
    else:
        os.system('cls')


def breakline():
    print('-'*60)


def main():
    lines = []
    for i in range(1, 5):
        clear()
        breakline()
        print(f'{i/4*100}%')
        breakline()
        url = 'https://scholarexpress.com/multiple-choice-questions-mcq-mathematics/{}'.format(i)
        soup = BeautifulSoup(requests.get(url).content, "lxml")
        soup = soup.find('div', attrs={'class': 'entry-content clearfix'})
        P = soup.findAll('p')[:]
        for p in P:
            if len(p.text.strip()) > 0:
                text = p.text
                temp = text.split('-')[1:]
                if len(temp) >= 1:
                    text = ''.join(temp)
                lines.append(text)
    with io.open('questions.txt', 'w', encoding="utf-8") as f:
        f.writelines([line+'\n' for line in lines])

    clear()
    print('Written to questions.txt')


if __name__ == '__main__':
    main()

