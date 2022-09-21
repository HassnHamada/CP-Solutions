# import sys


# sys.stdin = open("_input.txt", 'r')
# sys.stdout = open("_output.txt", 'w')


n = int(input())

print(n // 4 * ((n - n // 4 * 2) // 2))
