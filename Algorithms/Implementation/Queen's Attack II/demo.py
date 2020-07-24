

def isValidLoc(row, col):
    if row < n and row>=0 and col<n and col>=0 and [row, col] not in obstacles and [row, col] != [rq, cq]:
        return True
    return False


#inputs
n = 8 
k = 0
r_q = 1 
c_q = 1
obstacles = []
# obstacles = [[5, 5],
#             [4, 2],
#             [2, 3]]
##
rq = r_q - 1
cq = c_q - 1
obstacles = [[ob[0]-1, ob[1]-1] for ob in obstacles]

count = 0
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


count = sum(distList)

print("count: ", count)
# print("distlist: ", distList[0])