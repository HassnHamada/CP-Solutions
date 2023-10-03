#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 10;
char mat[N];

void run()
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%s", mat);
        for (int j = 0; j < N; j++)
        {
            if (mat[j] == '.')
            {
                continue;
            }
            ans += min({i + 1, j + 1, N - i, N - j});
        }
    }
    printf("%d\n", ans);
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