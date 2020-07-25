#https://www.hackerrank.com/challenges/encryption
import math
from itertools import zip_longest

text = "feedthedog"

low = math.floor(math.sqrt(len(text)))
high = math.ceil(math.sqrt(len(text)))

newText = []

for ind, char in enumerate(text):
    if ind ==0:
        newText.append(list(text[0:high]))
    if ind%high==0 and ind>=high :
        newText.append(list(text[ind:ind+high]))
        

result = list(zip_longest(*newText, fillvalue=''))
finalRes = ""
for res in result:
    for ch in res:
        finalRes += ch
    finalRes += ' '




# print(result)