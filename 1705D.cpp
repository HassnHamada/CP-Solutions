#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, L = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char sss[N], ttt[N], aaa[N], bbb[N];
int ccc[N], ddd[N];

void run()
{
    int n;
    scanf("%d", &n);
    scanf("%s", sss);
    scanf("%s", ttt);
    strcpy(aaa, sss);
    strcpy(bbb, ttt);
    unique(aaa, aaa + n + 1);
    unique(bbb, bbb + n + 1);
    for (int i = 1; aaa[i]; i++)
    {
        ccc[i] = find(sss + ccc[i - 1], sss + n, aaa[i]) - sss;
    }
    for (int i = 1; bbb[i]; i++)
    {
        ddd[i] = find(ttt + ddd[i - 1], ttt + n, bbb[i]) - ttt;
    }
    if (strcmp(aaa, bbb))
    {
        printf("-1\n");
    }
    else
    {
        ll ans = 0;
        queue<int> q;
        for (int i = 1, s1 = 0, s2 = 0, p = 0; i < n - 1; i++)
        {
            if (!q.empty() && i == abs(q.front()))
            {
                p ^= q.front() > 0 ? 1 : 2;
                q.pop();
            }
            if (p & 1)
            {
                ttt[i] = ttt[i] == '0' ? '1' : '0';
            }
            if (p & 2)
            {
                sss[i] = sss[i] == '0' ? '1' : '0';
            }
            s1 += sss[i - 1] != sss[i];
            s2 += ttt[i - 1] != ttt[i];
            if (sss[i] == ttt[i])
            {
                continue;
            }
            if (s1 > s2)
            {
                int j = ddd[s2 + 1];
                q.push(j);
                ttt[i] = sss[i];
                ans += j - i;
                s2 += 1;
                p ^= 1;
            }
            else
            {
                int j = ccc[s1 + 1];
                q.push(-j);
                sss[i] = ttt[i];
                ans += j - i;
                s1 += 1;
                p ^= 2;
            }
        }
        printf("%lld\n", ans);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
