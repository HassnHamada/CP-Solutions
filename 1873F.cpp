#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
int aaa[N], hhh[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", aaa + i);
        aaa[i] += aaa[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", hhh + i);
    }
    int ans = 0;
    for (int i = 0, j = 1; j <= n; j++)
    {
        assert(j > i);
        if (j - i > 1 && hhh[j - 1] % hhh[j])
        {
            i = j - 1;
        }
        while (aaa[j] - aaa[i] > k)
        {
            i++;
        }
        ans = max(ans, j - i);
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