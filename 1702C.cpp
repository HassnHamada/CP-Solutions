#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 31, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

map<int, int> fff, lll;

void run()
{

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        if (fff.find(v) == fff.end())
        {
            fff[v] = i;
        }
        lll[v] = i;
    }
    while (k--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (fff.find(u) == fff.end() || fff.find(v) == fff.end() || fff[u] > lll[v])
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    fff.clear();
    lll.clear();
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
