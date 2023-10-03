#include <bits/stdc++.h>
// #include <stdio.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;

int aaa[N], bbb[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int v = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", aaa + i);
        v ^= aaa[i];
    }
    int w = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", bbb + i);
        w |= bbb[i];
    }
    if (n & 1)
    {
        printf("%d %d\n", v, w | v);
    }
    else
    {
        printf("%d %d\n", v & ~w, v);
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