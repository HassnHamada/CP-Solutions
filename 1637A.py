def run():
    _ = input()
    arr = list(map(int, input().split()))
    if sorted(arr) == arr:
        print("NO")
    else:
        print("YES")


def main():
    t = int(input())
    for _ in range(t):
        run()


if __name__ == "__main__":
    main()
