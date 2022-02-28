from multiprocessing.connection import answer_challenge
from random import sample, randint
from collections import Counter
import sys


class Customer():
    def __init__(self) -> None:
        # self.like = set(int(i[10:]) for i in input().split()[1:])
        # self.dislike = set(int(i[10:]) for i in input().split()[1:])
        self.like = set(input().split()[1:])
        self.dislike = set(input().split()[1:])
        # for i in self.like:
        #     try:
        #         assert i[:10] == "ingredient"
        #     except AssertionError:
        #         print(i)
        #         exit(1)
        # for i in self.dislike:
        #     assert i[:10] == "ingredient"
        # self.like = set(int(i[10:]) for i in self.like)
        # self.dislike = set(int(i[10:]) for i in self.dislike)
        # self.num = 0
        # self.next = set()

    # def __str__(self) -> str:
    #     return f"I like: {' '.join(i for i in self.like)}\nI dislike: {' '.join(i for i in self.dislike)}\n----------"

    # def __lt__(self, other):
    #     return len(self.like) + len(self.dislike) < len(other.like) + len(other.dislike)
        # return self.num < other.num
        # a = sum(counter[i] for i in  self.dislike)
        # b = sum(counter[i] for i in  other.dislike)
        # return a < b
        # if len(self.like) == len(other.like):
        #     return len(self.dislike) < len(other.dislike)
        # return len(self.like) < len(other.like)


def score(customers, ingredients):
    ret = 0
    for customer in customers:
        if all(i in ingredients for i in customer.like) and all(i not in ingredients for i in customer.dislike):
            ret += 1
    return ret


def dp(ind: int, like: int, dislike: int):
    pass


# def dfs(ind, likes, dislikes, total):
#     global n, best, best_ans
#     # print(customer, n, customer == n)
#     if total + n - ind <= best_ans:
#         return
#     if ind == n:
#         best_ans = total
#         best = likes
#         return
#     if len(likes & customers[ind].dislike) == len(dislikes & customers[ind].like) == 0:
#         dfs(ind + 1, likes | customers[ind].like,
#             dislikes | customers[ind].dislike, total + 1)
#     dfs(ind + 1, likes, dislikes, total)


def main():
    # global n, customers
    n = int(input())
    customers = list(Customer() for _ in range(n))
    loved, hated = set(), set()
    for i in customers:
        loved |= i.like
    for i in customers:
        hated |= i.dislike
    not_hated = loved - hated
    ingredients = loved | hated
    best = set(input().split()[1:])
    # print(len(best), best)
    # print(sorted(ingredients))
    # print(len(ingredients), len(loved), len(hated), len(not_hated))
    # global best, best_ans
    # best_ans = 110
    # 4986 * 10000 * 10000
    # 9368 * 600 * 600
    # best = set(not_hated)
    # for i in customers:
    #     i.next = set(j for j in customers
    #                  if len(i.like & j.dislike) == len(i.dislike & j.like) == 0)

    # global ans
    # ans = 0
    # for i in range(n):
    # customers.sort(reverse=True)
    # dfs(0, set(), set(), 0)
    # for i in customers:
    #     i.num = sum(1 for j in customers if any(k in j.dislike for k in i.like))

    # customers.sort(reverse=True)
    # for i in customers:
    #     # if any(j in best for j in i.dislike):
    #     #     continue
    #     temp = best - i.like
    #     if score(customers, temp) > score(customers, best):
    #         best = temp

    # counter = Counter()
    # for i in customers:
    #     for j in i.dislike:
    #         if j not in counter:
    #             counter[j] = 0
    #         counter[j] -= 1
    # for i, _ in counter.most_common():
    #     temp = best | {i}
    #     if score(customers, temp) >= score(customers, best):
    #         best = temp

    # print(f"{len(best)} {' '.join(i for i in best)}")
    print(score(customers, best))


if __name__ == "__main__":
    with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
        sys.stdin = fin
        sys.stdout = fout
        main()
