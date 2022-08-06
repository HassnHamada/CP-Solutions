t = int(input())
for _ in range(t):
    inp = list(map(int, input().split()))
    inp.extend(map(int, input().split()))
    if all(i == 0 for i in inp):
        print(0)
    elif sum(inp) == 4:
        print(2)
    else:
        print(1)
