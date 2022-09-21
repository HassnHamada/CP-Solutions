# import sys


# sys.stdin = open("_input.txt", 'r')
# sys.stdout = open("_output.txt", 'w')


n = int(input())

print(sum(1 for i in map(int, list(str(n))) if i != 0 and n % i == 0))
