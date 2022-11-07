import sys


def main():
    n, x = map(int, input().split())
    arr = list(map(int, input().split()))
    fact = list()
    fact.append(1)
    for i in range(1, x+1):
        fact.append(fact[-1] * i)
    print("No" if sum(fact[i] for i in arr if i < x) % fact[x] else "Yes")


if __name__ == "__main__":
    # with open("_input.txt", "r") as inf, open("_output.txt", "w") as outf:
    #     sys.stdin = inf
    #     sys.stdout = outf
    main()
