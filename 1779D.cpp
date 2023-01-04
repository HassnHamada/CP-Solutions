#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 18, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int aaa[N], bbb[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", aaa + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", bbb + i);
    }
    int m;
    scanf("%d", &m);
    multiset<int> xxx;
    for (int i = 0, v; i < m; i++)
    {
        scanf("%d", &v);
        xxx.insert(v);
    }
    bool ok = true;
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (aaa[i] < bbb[i])
        {
            ok = false;
            break;
        }
        while (!stk.empty() && stk.top() < bbb[i])
        {
            stk.pop();
        }
        if (aaa[i] == bbb[i])
        {
            continue;
        }
        if (stk.empty() || stk.top() > bbb[i])
        {
            if (xxx.find(bbb[i]) == xxx.end())
            {
                ok = false;
                break;
            }
            stk.push(bbb[i]);
            xxx.erase(xxx.find(bbb[i]));
        }
    }
    printf(ok ? "YES\n" : "NO\n");
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