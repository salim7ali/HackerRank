# https://www.hackerrank.com/challenges/triangle-quest-2/problem

def patternGen(N):
    for i in range(1, N+1):

        for j in range(1, i):
            print(j, end="")

        for j in range(i, 0, -1):
            print(j, end="")

        print()

def delmosNumbers(N):
    for i in range(1, N+1):
        print((((10**i)-1)//9)**2)

# patternGen(5)

delmosNumbers(5)