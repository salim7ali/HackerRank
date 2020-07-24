# https://www.hackerrank.com/challenges/queens-attack-2

#!/bin/python3

import math
import os
import random
import re
import sys

def queensAttack(n, k, r_q, c_q, obstacles):

    rq = r_q - 1
    cq = c_q - 1
    obstacles = [[ob[0]-1, ob[1]-1] for ob in obstacles]

    distList = []
    #case 0
    if cq>=rq:
        distList.append(rq)    
    else:
        distList.append(cq)
    #case 1
    distList.append(rq)
    #case 2
    if cq<=n-rq-1:
        distList.append(rq)    
    else:
        distList.append(n-cq-1)
    #case 3
    distList.append(n-cq-1)
    #case 4
    if n-rq-1<=n-cq-1:
        distList.append(n-rq-1)    
    else:
        distList.append(n-cq-1)
    #case 5
    distList.append(n-rq-1)
    #case 6
    if cq>=n-rq-1:
        distList.append(n-rq-1)    
    else:
        distList.append(cq)
    #case 7
    distList.append(cq)



    #case 0
    for obs in obstacles:
        if rq-obs[0] == cq-obs[1] and rq-obs[0]>0 and distList[0]>rq-obs[0]: 
            distList[0] = rq-obs[0]-1
    #case 1
    for obs in obstacles:
        if cq == obs[1] and rq-obs[0]>0 and distList[1]>rq-obs[0]: 
            distList[1] = rq-obs[0]-1
    #case 2
    for obs in obstacles:
        if rq-obs[0] == obs[1]-cq and rq-obs[0]>0 and obs[1]-cq>0 and distList[2]>rq-obs[0]: 
            distList[2] = rq-obs[0]-1
    #case 3
    for obs in obstacles:
        if rq == obs[0] and obs[1]-cq>0 and distList[3]>obs[1]-cq: 
            distList[3] = obs[1]-cq-1
    #case 4
    for obs in obstacles:
        if obs[0]-rq == obs[1]-cq and obs[0]-rq>0 and distList[4]>obs[0]-rq: 
            distList[4] = obs[0]-rq-1
    #case 5
    for obs in obstacles:
        if cq == obs[1] and obs[0]-rq>0 and distList[5]>obs[0]-rq: 
            distList[5] = obs[0]-rq-1
    #case 6
    for obs in obstacles:
        if obs[0]-rq == cq-obs[1] and obs[0]-rq>0 and cq-obs[1]>0 and distList[6]>obs[0]-rq: 
            distList[6] = obs[0]-rq-1
    #case 7
    for obs in obstacles:
        if rq == obs[0] and cq-obs[1]>0 and distList[7]>cq-obs[1]: 
            distList[7] = cq-obs[1]-1

    return sum(distList)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    r_qC_q = input().split()

    r_q = int(r_qC_q[0])

    c_q = int(r_qC_q[1])

    obstacles = []

    for _ in range(k):
        obstacles.append(list(map(int, input().rstrip().split())))

    result = queensAttack(n, k, r_q, c_q, obstacles)

    fptr.write(str(result) + '\n')

    fptr.close()
