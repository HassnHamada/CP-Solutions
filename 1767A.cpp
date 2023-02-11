#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 5e2 + 10, M = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

bool ok(std::vector<std::pair<int, int>> &pts)
{
    for (int i = 0; i < M; i++)
    {
        int x = pts[i].first, y = pts[i].second;
        int mnx = std::min(pts[(i - 1 + M) % M].first, pts[(i + 1) % M].first),
            mxx = std::max(pts[(i - 1 + M) % M].first, pts[(i + 1) % M].first);
        int mny = std::min(pts[(i - 1 + M) % M].second, pts[(i + 1) % M].second),
            mxy = std::max(pts[(i - 1 + M) % M].second, pts[(i + 1) % M].second);
        if ((mnx < x && x < mxx) || (mny < y && y < mxy))
        {
            return true;
        }
    }
    return false;
}

void run()
{
    std::vector<std::pair<int, int>> pts(M);
    for (auto &&[i, j] : pts)
    {
        scanf("%d%d", &i, &j);
    }
    printf(ok(pts) ? "YES\n" : "NO\n");
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}