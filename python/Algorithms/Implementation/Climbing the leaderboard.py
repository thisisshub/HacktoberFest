from bisect import bisect_right


def climbingLeaderboard(scores, alice):
    for i in alice:
        print(len(scores) - bisect_right(scores, i) + 1)


if __name__ == '__main__':
    scores_count = int(input())

    scores = sorted(set(map(int, input().rstrip().split())))

    alice_count = int(input())

    alice = list(map(int, input().rstrip().split()))

    climbingLeaderboard(scores, alice)
