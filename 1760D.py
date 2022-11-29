import sys


def main():
    n = int(input())
    arr = list(map(int,  input().split()))

    def gen():
        i = j = 0
        while i < n:
            while j + 1 < n and arr[j + 1] == arr[i]:
                j += 1
            yield i, j
            i = j = j + 1
    cnt = 0
    for i, j in gen():
        if (i == 0 or arr[i - 1] > arr[i]) and (j == n - 1 or arr[j] < arr[j + 1]):
            cnt += 1    
    print("yes" if cnt == 1 else "NO")


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
