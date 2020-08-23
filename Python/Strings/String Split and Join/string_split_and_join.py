def split_and_join(line):
    result = ""
    words = line.split()
    result = '-'.join(words)
    return result
    # write your code here

if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)