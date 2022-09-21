#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 1e2 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

// int aaa[N], bbb[N];
int F(int v)
{
    assert(v);
    int ret = 0;
    while (v)
    {
        v /= 10;
        ret += 1;
    }
    return ret;
}

void run()
{
    int n;
    scanf("%d", &n);
    map<int, int, greater<int>> aaa, bbb;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        aaa[v] += 1;
    }
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        if (aaa[v])
        {
            aaa[v] -= 1;
        }
        else
        {
            bbb[v] += 1;
        }
    }
    int ans = 0;
    while (!aaa.empty())
    {
        // cout << aaa.size() << " " << bbb.size() << endl;
        if (aaa.begin()->second == 0)
        {
            aaa.erase(aaa.begin());
            continue;
        }
        while (bbb.begin()->second == 0)
        {
            bbb.erase(bbb.begin());
            assert(!bbb.empty());
        }
        assert(!bbb.empty());
        int a = aaa.begin()->first,
            b = bbb.begin()->first;
        assert(a != b);
        assert(aaa[a]);
        assert(bbb[b]);
        if (a > b)
        {
            int na = F(a);
            aaa[a] -= 1;
            if (bbb[na])
            {
                bbb[na] -= 1;
            }
            else
            {
                aaa[na] += 1;
            }
        }
        else
        {
            int nb = F(b);
            bbb[b] -= 1;
            if (aaa[nb])
            {
                aaa[nb] -= 1;
            }
            else
            {
                bbb[nb] += 1;
            }
        }
        ans += 1;
    }
    printf("%d\n", ans);
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