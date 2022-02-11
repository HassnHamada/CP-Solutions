from grf_vis import GraphVisualization
import heapq
import sys


def dijkstra(start, grf, n, grf_):
    pq = []
    dis = [float("inf")] * n
    dis[start] = 0
    heapq.heappush(pq, (dis[start], start))
    grf_.visualize()
    while len(pq):
        t = heapq.heappop(pq)
        if t[0] != dis[t[1]]:
            continue
        grf_.node_color[t[1]] = '#00ff00'
        # print(grf_.node_color)
        grf_.visualize()
        for v, c in grf[t[1]]:
            if t[0] + c >= dis[v]:
                continue
            dis[v] = t[0] + c
            heapq.heappush(pq, (dis[v], v))
    return dis


def main():
    n, m = map(int, input().split())
    grf = [list() for _ in range(n)]
    grf_ = GraphVisualization(n)

    for i in range(m):
        u, v, c = tuple(map(int, input().split()))
        grf[u].append((v, c))
        grf_.addEdge(u, v, c)

    # grf_.visualize()
    # print(grf_.visual)
    start = int(input())
    for i, v in enumerate(dijkstra(start, grf, n, grf_)):
        print(i, v)


if __name__ == "__main__":
    with open("_input.txt", "r") as inf, open("_output.txt", "w") as outf:
        sys.stdin = inf
        sys.stdout = outf
        main()
