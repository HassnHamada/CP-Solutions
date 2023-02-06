#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int aaa[N], bbb[N];

void run()
{
    int n, w, h;
    scanf("%d%d%d", &n, &w, &h);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", aaa + i);
    }
    // assert(is_sorted(aaa, aaa + n));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", bbb + i);
    }
    // assert(is_sorted(bbb, bbb + n));
    pair<int, int> p = {-INF, INF};
    for (int i = 0; i < n; i++)
    {
        pair<int, int> t = {bbb[i] - w + h - aaa[i],
                            bbb[i] + w - h - aaa[i]};
        // assert(t.first <= t.second);
        p.first = max(p.first, t.first);
        p.second = min(p.second, t.second);
    }
    // printf("%d %d\n", p.first, p.second);
    printf(p.first <= p.second ? "YES\n" : "NO\n");
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