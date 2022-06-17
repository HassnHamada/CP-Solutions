from collections import Counter
import sys


def run():
    _ = int(input())
    arr = list(map(int, input().split()))
    counter = Counter(arr)
    if 1 not in counter:
        print("YES")
        return
    if 1 in counter and (0 in counter or 2 in counter):
        print("NO")
        return
    counter.pop(1)
    p = 0
    for i in sorted(counter.keys()):
        if i == p + 1:
            print("NO")
            return
        p = i
    print("YES")


# with open("_input.txt", 'r') as fin, open("_output.txt", 'w') as fout:
#     sys.stdin = fin
#     sys.stdout = fout
t = int(input())
for _ in range(t):
    run()
