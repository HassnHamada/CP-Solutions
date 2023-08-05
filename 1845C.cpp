// #include <bits/stdc++.h>
#include <stdio.h>
#include <set>
#include <iostream>
using namespace std;
typedef long long ll;

// const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
const int N = 3e5 + 10, M = 11;

char str[N], l[M], h[M], c[M];

int nxt[N][M - 1];

bool next(int m)
{
    c[m - 1]++;
    for (int i = m - 1; ~i; i--)
    {
        if (c[i] > h[i])
        {
            if (i)
            {
                c[i - 1]++;
                c[i] = l[i];
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

void run()
{
    int m;
    scanf("%s%d%s%s", str + 1, &m, l, h);
    int n = strlen(str + 1);
    for (int j = 0; j < M - 1; j++)
    {
        nxt[n][j] = -1;
    }
    for (int i = n - 1; ~i; i--)
    {
        for (int j = 0; j < M - 1; j++)
        {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][str[i + 1] - '0'] = i + 1;
    }
    strcpy(c, l);
    bool ok = false;
    do
    {
        // printf("%s\n", c);
        for (int i = 0, j = 0; !ok && i < m; i++)
        {
            if (~nxt[j][c[i] - '0'])
            {
                j = nxt[j][c[i] - '0'];
            }
            else
            {
                ok = true;
            }
        }
    } while (!ok && next(m));

    printf(ok ? "YES\n" : "NO\n");
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