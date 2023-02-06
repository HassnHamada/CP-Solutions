#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int ppp[N], qqq[N];
pair<int, int> inp[N];

bool solve(int n)
{
    set<int> ppp_s, qqq_s;
    for (int i = 0; i < n; i++)
    {
        ppp_s.insert(i + 1);
        qqq_s.insert(i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        assert(!ppp_s.empty());
        assert(!qqq_s.empty());
        if (ppp_s.find(inp[i].first) == ppp_s.end())
        {
            if (qqq_s.find(inp[i].first) == qqq_s.end())
            {
                return false;
            }
            else
            {
                ppp[inp[i].second] = *ppp_s.begin();
                qqq[inp[i].second] = inp[i].first;
                ppp_s.erase(ppp_s.begin());
                qqq_s.erase(inp[i].first);
            }
        }
        else
        {
            ppp[inp[i].second] = inp[i].first;
            qqq[inp[i].second] = *qqq_s.begin();
            ppp_s.erase(inp[i].first);
            qqq_s.erase(qqq_s.begin());
        }
        assert(max(qqq[inp[i].second], ppp[inp[i].second]) >= inp[i].first);
        if (max(qqq[inp[i].second], ppp[inp[i].second]) > inp[i].first)
        {
            return false;
        }
    }
    return true;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inp[i].first);
        inp[i].second = i;
    }
    sort(inp, inp + n);
    if (solve(n))
    {
        for (int i = 0; i < n; i++)
        {
            auto [j, k] = inp[i];
            assert(max(ppp[k], qqq[k]) == j);
        }
        printf("YES\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", ppp[i], " \n"[i + 1 == n]);
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", qqq[i], " \n"[i + 1 == n]);
        }
    }
    else
    {
        printf("NO\n");
    }
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