from ast import expr
import sys


def run():
    n = int(input())
    while True:
        ret = nextInd()
        if ret == -1:
            exit(1)


def main():
    t = int(input())
    for _ in range(t):
        run()


if __name__ == "__main__":
    main()
