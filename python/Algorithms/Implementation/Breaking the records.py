def breakingRecords(scores):
    c=0
    v=0
    highest = scores[0]
    lowest = scores[0]
    for i in range(len(scores)):
       if scores[i] > highest:
           highest = scores[i]
           c+=1
       elif scores[i] < lowest:
           lowest = scores[i]
           v+=1
    print(c,v,sep=' ')


if __name__ == '__main__':

    n = int(input())

    scores = list(map(int, input().rstrip().split()))

    breakingRecords(scores)
