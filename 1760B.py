import sys
from string import ascii_lowercase


def main():
    _ = int(input())
    print(max(ascii_lowercase.index(i)+1 for i in input()))


stdout = sys.stdout
stdin = sys.stdin

try:
    with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
        sys.stdin = fin
        sys.stdout = fout
        t = int(input())
        for _ in range(t):
            main()
except FileNotFoundError:
    t = int(input())
    for _ in range(t):
        main()
