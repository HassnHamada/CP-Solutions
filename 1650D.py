import sys

# O(n)


def run():
    n = int(input())
    arr = list(map(int, input().split()))
    nxt, prv, ind = [0] * (n+1), [0] * (n+1), [0] * (n+1)
    for i in range(n):
        if i != n - 1:
            nxt[arr[i]] = arr[i+1]
        if i != 0:
            prv[arr[i]] = arr[i-1]
        ind[arr[i]] = i
    h, t = arr[0], arr[-1]
    for i in range(n, 0, -1):
        if t == i:
            t = prv[i]
        else:
            nxt_i = nxt[i]
            nxt[i] = nxt[t]
            nxt[t] = h
            prv[h] = t
            prv[(h := nxt_i)] = 0
            nxt[(t := prv[i])] = i
        # prn = h
        # while True:
        #     print(prn, end=" ")
        #     if nxt[prn] == 0:
        #         break
        #     prn = nxt[prn]
        # print()


# O(n^2)
# def run():
#     n = int(input())
#     arr = list(map(int, input().split()))
#     ans = list()
#     for i in range(n-1, -1, -1):
#         if arr[i] == i + 1:
#             ans.append(0)
#         else:
#             j = arr.index(i+1) + 1
#             arr = arr[j:i+1] + arr[:j] + arr[i+1:]
#             ans.append(j)
#     print(*ans[::-1])


def main():
    t = int(input())
    for _ in range(t):
        run()


if __name__ == "__main__":
    try:
        with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
            sys.stdin = fin
            sys.stdout = fout
            main()
    except IOError:
        main()
