# https://www.hackerrank.com/challenges/capitalize/problem

import string

def solve(s):
    result = ""
    words = s.split()
    for word in words:
        if(word[0].isalpha()):
            result += word.capitalize()
        else:
            result += word
        result += ' '
    return result

text = "1 w 2 r 3g"
print(solve(text))