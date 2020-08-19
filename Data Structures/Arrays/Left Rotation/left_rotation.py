# https://www.hackerrank.com/challenges/array-left-rotation/problem

n = 5 
d = 4
nums = [1, 2, 3, 4, 5]

def leftRotation(n, d, nums):

    result = nums[d%n:]
    result.extend(nums[0:d%n])

    print(result)

leftRotation(n, d, nums) 