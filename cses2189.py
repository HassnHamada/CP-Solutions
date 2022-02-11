# import sys


def run():
    inp = list(map(int, input().split()))
    p1, p2, p3 = ((i, j) for i, j in zip(inp[::2], inp[1::2]))
    if p1[0] > p2[0]:
        p1, p2 = p2, p1
    v1 = (p2[0] - p1[0], p2[1] - p1[1])
    v2 = (p3[0] - p1[0], p3[1] - p1[1])
    ret = v2[0] * v1[1] - v2[1] * v1[0]
    if ret == 0:
        return 0
    return 1 if ret > 0 else -1


def main():
    t = int(input())
    ans = {-1: "LEFT", 0: "TOUCH", 1: "RIGHT"}
    for _ in range(t):
        print(ans[run()])


# if __name__ == "__main__":
#     with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
#         sys.stdin = fin
#         sys.stdout = fout
#         main()
main()