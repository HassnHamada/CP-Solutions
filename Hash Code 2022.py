import sys


class Contributor():
    def __init__(self) -> None:
        self.name, n = input().split()
        self.skills = dict()
        self.available = 0
        for _ in range(int(n)):
            inp = input().split()
            # print(inp)
            self.skills[inp[0]] = int(inp[1])

    def __str__(self) -> str:
        skills_str = list()
        for i in self.skills:
            skills_str.append(f"{i}")
        return f"{self.name}\n{' '.join(skills_str)}"

    def __hash__(self) -> int:
        return hash(self.name)


class Project():
    def __init__(self) -> None:
        inp = input().split()
        self.name = inp[0]
        self.duration = int(inp[1])
        self.score = int(inp[2])
        self.best = int(inp[3])
        self.roles: dict[str, list] = dict()
        self.ans = [None] * int(inp[4])
        for i in range(int(inp[4])):
            inp = input().split()
            if inp[0] not in self.roles:
                self.roles[inp[0]] = list()
            self.roles[inp[0]].append((int(inp[1]), i))

    def __lt__(self, other):
        # return self.best < other.best
        # return self.score < other.score
        # s1 = self.score if self.best - \
        #     self.duration >= 0 else max(0, self.score + self.best - self.duration)
        # s2 = other.score if other.best - \
        #     other.duration >= 0 else max(0, other.score + other.best - other.duration)
        # return s1 < s2
        return len(self.ans) < len(other.ans)
        # if self.best - self.duration == other.best - other.duration:
        #     return self.score >= other.score
        # return self.best - self.duration < other.best - other.duration


def score():
    pass


def can_start(project: Project, contributors: list[Contributor]):
    can_work: dict[tuple[str, int], Contributor] = dict()
    for k, arr in project.roles.items():
        for v, i in arr:
            mn = (float("inf"), None)
            for contributor in contributors:
                # if contributor not in can_work and k in contributor.skills and contributor.skills[k] >= v:
                if contributor not in can_work.values() and k in contributor.skills and mn[0] > contributor.skills[k] >= v:
                    # can_work[(k, i)] = contributor
                    # project.ans[(i)] = contributor
                    mn = (v, contributor)
                    # break
            if mn[1] is not None:
                can_work[(k, i)] = mn[1]
    if len(can_work) == sum(len(i) for i in project.roles.values()):
        mx = max(i.available for i in can_work.values())
        for k, arr in project.roles.items():
            # print(k, v, i)
            for v, i in arr:
                project.ans[i] = can_work[(k, i)].name
                can_work[(k, i)].available = mx + project.duration
                if v == can_work[(k, i)].skills[k]:
                    can_work[(k, i)].skills[k] += 1
        assert all(i is not None for i in project.ans)
        return True
    # if all(i is not None for i in project.ans):
    #     return True
    # for i in range(len(project.ans)):
    #     project.ans[i] = None
    return False


def main():
    c, p = map(int, input().split())
    contributors = list(Contributor() for _ in range(c))
    projects: list[Project] = list()
    for _ in range(p):
        projects.append(Project())
        if projects[-1].best - projects[-1].duration < 0:
            projects.pop()
    ans: list[Project] = list()
    projects.sort()
    # projects.sort(reverse=True)
    again = True
    while again:
        again = False
        for i in projects:
            # print(i.name)
            if i not in ans and can_start(i, contributors):
                # print(i.name)
                ans.append(i)
                again = True
    print(len(ans))
    # print(*(i.name for i in ans))
    for i in ans:
        print(i.name)
        # print(" ".join(j.name for j in i.ans))
        print(" ".join(i.ans))


if __name__ == "__main__":
    with open("_input.txt", "r") as fin, open("_output.txt", "w") as fout:
        sys.stdin = fin
        sys.stdout = fout
        main()
