import sys


def main():
    _, k = map(int, input().split())
    arr = list(set(map(lambda x: int(x) % k, input().split())))
    vis = [False] * k

    def solve(v=0):
        if not vis[v]:
            vis[v] = True
            for i in arr:
                solve((v + i) % k)
    
    solve(min(arr))
    print(sum(vis))
    print(*(i for i, v in enumerate(vis) if v))


with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
    sys.stdin = fin
    sys.stdout = fout
    main()
