# Enter your code here. Read input from STDIN. Print output to STDOUT
import itertools 
number = input()
grouped = itertools.groupby(number)

for key, group in grouped:
    temp = (len(list(group)), int(key))
    print(temp, end=' ')
