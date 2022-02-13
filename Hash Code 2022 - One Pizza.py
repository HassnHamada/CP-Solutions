from random import sample, randint
import sys


class Customer():
    def __init__(self) -> None:
        self.like = set(input().split()[1:])
        self.dislike = set(input().split()[1:])

    def __str__(self) -> str:
        return f"I like: {' '.join(i for i in self.like)}\nI dislike: {' '.join(i for i in self.dislike)}\n----------"

    def __lt__(self, other):
        if len(self.like) == len(other.like):
            return len(self.dislike) < len(other.dislike)
        return len(self.like) < len(other.like)


def score(customers, ingredients):
    ret = 0
    for customer in customers:
        if all(i in ingredients for i in customer.like) and all(i not in ingredients for i in customer.dislike):
            ret += 1
    return ret


def main():
    customers = list()
    ingredients = set()
    n = int(input())
    for _ in range(n):
        customers.append(Customer())
        ingredients |= customers[-1].like | customers[-1].dislike
    best = set()
    customers.sort()
    for i in customers:
        if any(j in best for j in i.dislike):
            continue
        best |= i.like
    # for _ in range(100):
    #     temp = best - set(sample(best, randint(0, min(3, len(best)))))
    #     temp |= set(sample(ingredients - best,
    #                 randint(0, min(3, len(ingredients - best)))))
    #     if score(customers, temp) > score(customers, best):
    #         best = temp
    print(f"{len(best)} {' '.join(i for i in best)}")
    print(score(customers, best))


if __name__ == "__main__":
    with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
        sys.stdin = fin
        sys.stdout = fout
        main()
