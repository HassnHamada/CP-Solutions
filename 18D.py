import sys

with open("_input.txt", "r") as inf, open("_output.txt", "w") as outf:
    sys.stdin = inf
    sys.stdout = outf
    n = int(input())
    arr = list()
    sss, www = dict(), dict()
    for i in range(n):
        s, v = input().split()
        v = int(v) + 1
        arr.append(v)
        if s[0] == 's':
            arr[-1] *= -1   
            sss[v] = i
        else:
            if v not in www:
                www[v] = list()
            www[v].append(i)
    ans = 0
    for i in sorted(sss.keys(), reverse=True):
        if i not in www:
            continue
        while len(www[i]) and www[i][-1] > sss[i]:
            www[i].pop()
        if len(www[i]) and all(arr[j] for j in range(www[i][-1], sss[i]+1)):
            for j in range(www[i][-1], sss[i]+1):
                arr[j] = 0
            ans += 2**(i - 1)
    print(ans)
