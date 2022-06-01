#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3 + 10, M = 20, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
bool vis[N][N];
char grf[N][N];

struct Node
{
    int r, c, x, y;
};

void run()
{
    int n, m;
    Node s;
    scanf("%d%d%d%d%d%d", &n, &m, &s.r, &s.c, &s.x, &s.y);
    s.r--, s.c--;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(grf + i));
    }
    queue<Node> q;
    q.push(s);
    while (q.size())
    {
        // cout << q.size() << endl;
        queue<Node> t;
        while (q.size())
        {
            Node f = q.front();
            q.pop();
            if (grf[f.r][f.c] == '*' || vis[f.r][f.c] || f.r < 0 || f.r >= n || f.c < 0 || f.c >= m || f.x < 0 || f.y < 0)
            {
                continue;
            }
            for (int i = 0; f.r + i < n && grf[f.r + i][f.c] == '.'; i++)
            {
                vis[f.r + i][f.c] = true;
                t.push({f.r + i, f.c + 1, f.x, f.y - 1});
                t.push({f.r + i, f.c - 1, f.x - 1, f.y});
            }
            for (int i = 1; f.r - i >= 0 && grf[f.r - i][f.c] == '.'; i++)
            {
                vis[f.r - i][f.c] = true;
                t.push({f.r - i, f.c + 1, f.x, f.y - 1});
                t.push({f.r - i, f.c - 1, f.x - 1, f.y});
            }
        }
        swap(t, q);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += count((bool *)(vis + i), (bool *)(vis + i) + m, 1);
    }
    printf("%d\n", ans);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}