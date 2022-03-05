class Solution:
    def robotSim(self, commands: list[int], obstacles: list[list[int]]) -> int:
        obstacles_v, obstacles_h = dict(), dict()
        for x, y in obstacles:
            if x not in obstacles_v:
                obstacles_v[x] = set()
            obstacles_v[x].add(y)
            if y not in obstacles_h:
                obstacles_h[y] = set()
            obstacles_h[y].add(x)
        # 0b0001 North
        # 0b0010 East
        # 0b0100 South
        # 0b1000 West
        direction = 0b0001
        ans = 0
        pos = (0, 0)
        for command in commands:
            if command == -1:
                direction <<= 1
                if direction == 16:
                    direction = 1
            elif command == -2:
                direction >>= 1
                if direction == 0:
                    direction = 8
            else:
                if direction == 1:
                    for _ in range(command):
                        if pos[0] in obstacles_v and pos[1]+1 in obstacles_v[pos[0]]:
                            break
                        pos = (pos[0], pos[1] + 1)
                if direction == 2:
                    for _ in range(command):
                        if pos[1] in obstacles_h and pos[0]+1 in obstacles_h[pos[1]]:
                            break
                        pos = (pos[0] + 1, pos[1])
                if direction == 4:
                    for _ in range(command):
                        if pos[0] in obstacles_v and pos[1]-1 in obstacles_v[pos[0]]:
                            break
                        pos = (pos[0], pos[1] - 1)
                if direction == 8:
                    for _ in range(command):
                        if pos[1] in obstacles_h and pos[0]-1 in obstacles_h[pos[1]]:
                            break
                        pos = (pos[0] - 1, pos[1])
                ans = max(ans, pos[0]**2 + pos[1]**2)
        return ans
