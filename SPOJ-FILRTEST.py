# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")


def computeZ(str: str, ret: list):
    n = len(str)
    ret.append(n)
    s = e = 0
    for i in range(1, n):
        if i >= e:
            s = e = i
            ret.append(0)
        else:
            ret.append(ret[i-s])
        if i + ret[i] >= e:
            s = i
            while e < n and str[e] == str[e-s]:
                e += 1
            ret[i] = e - s


while True:
    k, s = input().split()
    if k == '-1':
        break
    k, n = int(k), len(s)
    ans = k // n
    if k >= n:
        z_arr = list()
        computeZ(s, z_arr)
        for i, v in enumerate(z_arr):
            if v in {0, n}:
                continue
            ans = max(ans, (k - n) // (n - v) + 1)
    print(ans)
