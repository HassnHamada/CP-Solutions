import sys

def main():
    n = int(input())
    db = dict()
    for _ in range(n):
        name = input()
        if name in db:
            print(f"{name}{db[name]}")
        else:
            print("OK")
            db[name] = 0
        db[name] += 1

if __name__ == "__main__":
    try:
        with open("_input.txt", "r") as inf, open("_output.txt", "w") as outf:
            sys.stdin = inf
            sys.stdout = outf
            main()
    except:
        main()