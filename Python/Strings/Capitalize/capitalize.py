# https://www.hackerrank.com/challenges/capitalize/problem

import string

def solve(s):
    result = ""
    # words = s.split()
    for ind, char in enumerate(s):
        if(ind == 0):
            result += char.capitalize()
        elif s[ind-1]==' ' and char.isalpha():
            result += char.capitalize()
        else:
            result += char

    return result

# text = "1 w 2 r 3g"
text = "hello world"
print(solve(text))