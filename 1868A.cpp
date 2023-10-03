#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
// #include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", m == 1 ? 0 : min(n + 1, m));
    for (int i = 0; i < min(n, m - 1); i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d%c", (j + i) % m, " \n"[j + 1 == m]);
        }
    }
    for (int i = min(n, m - 1); i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d%c", j, " \n"[j + 1 == m]);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}