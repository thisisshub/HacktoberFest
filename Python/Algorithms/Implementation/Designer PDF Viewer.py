def designerPdfViewer(h, word):
    c=[]
    for i in word:
        c.append(h[(ord(i) - ord('a'))])
    print(max(c)*len(word))


if __name__ == '__main__':
    h = list(map(int, input().rstrip().split()))

    word = input()

    designerPdfViewer(h, word)
