#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 3e3;
vector<int> graph[N];
struct
{
    int xPos, yPos, center, field;
} fighters[N];

bool vis[N], checked[N];
int seen[N];

double angle(int x1, int y1, int x2, int y2)
{
    return atan2(x1 * y2 - y1 * x2, x1 * x2 + y1 * y2);
}

double angle(pair<int, int> p1, pair<int, int> p2)
{
    return angle(p1.first, p1.second, p2.first, p2.second);
}

double Xangle(pair<int, int> p)
{
    return angle(1, 0, p.first, p.second);
}

double Xangle(int x, int y)
{
    return angle(1, 0, x, y);
}

bool cycle(int node)
{
    if (vis[node])
    {
        return true;
    }
    vis[node] = true;
    checked[node] = true;
    for (int i = 0; i < graph[node].size(); i++)
    {
        if (cycle(graph[node][i]))
        {
            return true;
        }
    }
    vis[node] = false;
    return false;
}

int dfs(int node)
{
    printf("%d ", node + 1);
    int ret = 1;
    for (auto &&i : graph[node])
    {
        assert(seen[i] != 0);
        seen[i] -= 1;
        if (!seen[i])
        {
            ret += dfs(i);
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> fighters[i].xPos >> fighters[i].yPos >> fighters[i].center >> fighters[i].field;
    }
    for (int i = 0; i < n; i++)
    {
        int visionStart = fighters[i].center - fighters[i].field,
               visionEnd = fighters[i].center + fighters[i].field;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            double radAngle = Xangle(fighters[j].xPos - fighters[i].xPos, fighters[j].yPos - fighters[i].yPos), degAngle = radAngle * 180.0 / (2.0 * acos(0.0));
            if (degAngle < 0.0)
            {
                degAngle = 360.0 + degAngle;
            }
            // cout << i << " " << j << " " << degAngle << endl;
            if (degAngle >= visionStart && degAngle <= visionEnd)
            {
                graph[i].push_back(j);
                seen[j] += 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!checked[i] && cycle(i))
        {
            printf("-1\n");
            return 0;
        }
    }

    for (int i = 0, j = 0; j < n; i = (i + 1) % n)
    {
        if (seen[i])
        {
            continue;
        }
        j += dfs(i);
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}