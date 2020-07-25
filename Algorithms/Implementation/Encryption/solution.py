#https://www.hackerrank.com/challenges/encryption
#!/bin/python3

import math
import os
import random
import re
import sys
from itertools import zip_longest

# Complete the encryption function below.
def encryption(text):

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
    return finalRes

        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = encryption(s)

    fptr.write(result + '\n')

    fptr.close()