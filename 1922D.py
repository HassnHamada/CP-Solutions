import sys
from typing import Any

stdin = sys.stdin
stdout = sys.stdout

sys.stdin = open('_input.txt', 'r')
sys.stdout = open('_output.txt', 'w')

class Monster:
    def __init__(self, idx, attack, defens, left=None, right=None):
        self.idx = idx
        self.attack = attack
        self.defens = defens
        self.left = left
        self.right = right
        self.dead = self.rm = False


def monsters_killed_in_each_round(t, test_cases):
    results = list()

    for _ in range(t):
        n, attacks, defenses = test_cases[_]
        monsters = list()
        for i in range(n):
            monsters.append(Monster(i, attacks[i], defenses[i]))
        for i in range(1, n):
            monsters[i].left = monsters[i - 1]
        for i in range(n - 1):
            monsters[i].right = monsters[i + 1]
        may_die = set(range(n))
        answer = list()
        for _ in range(n):
            dead = set()
            for i in may_die:
                # Calculate damage received for each monster in each round
                monster = monsters[i]
                damage = monster.left.attack if monster.left else 0
                damage += monster.right.attack if monster.right else 0
                if damage > monster.defens:
                    dead.add(i)
                    monster.dead = True

            # Add the number of monsters killed in this round to the answer
            answer.append(len(dead))
            # Update the monster order and may_die set
            may_die = set()
            for i in dead:
                monster = monsters[i]
                if monster.rm:
                    continue
                left, right = monster.left, monster.right
                while left and left.dead:
                    left.rm = True
                    left = left.left
                while right and right.dead:
                    right.rm = True
                    right = right.right
                if left:
                    left.right = right
                    may_die.add(left.idx)
                if right:
                    right.left = left
                    may_die.add(right.idx)
                monster.rm = True

        results.append(answer)

    return results

# Input processing
t = int(input())
test_cases = []

for _ in range(t):
    n = int(input())
    attacks = list(map(int, input().split()))
    defenses = list(map(int, input().split()))
    test_cases.append((n, attacks, defenses))

# Solve the problem
output = monsters_killed_in_each_round(t, test_cases)

# Output the results
for result in output:
    print(" ".join(map(str, result)))
