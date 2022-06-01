#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
// int arr[N];
map<int, int> mmm;

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    mmm.clear();
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        mmm[v]++;
    }
    int a = 0, al = -1, ar = -1, c = 0, cl, cr = -1;
    for (auto &&i : mmm)
    {
        if (i.second < k)
        {
            c = 0;
            cr = -1;
            continue;
        }
        if (cr != -1 && i.first != cr + 1)
        {
            c = 0;
            cr = -1;
        }
        if (!c)
        {
            cl = i.first;
        }
        c++;
        cr = i.first;
        if (c > a)
        {
            a = c;
            al = cl;
            ar = cr;
        }
    }
    if (al == -1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d %d\n", al, ar);
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