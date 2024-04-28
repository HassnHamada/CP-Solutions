#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <stdio.h>
#include <string.h>
#include <assert.h>
#endif
using namespace std;
typedef long long ll;

const int N = (int)(2e5 + 10);
int frq[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        frq[v]++;
    }
    int ans = 0;
    for (int i = 0; ans < n; ans++)
    {
        if (frq[ans] == 0)
            break;
        if (frq[ans] == 1)
        {
            if (i++)
            {
                break;
            }
        }
    }
    // assert(ans <= (n + 1) / 2);
    printf("%d\n", ans);
    memset(frq, 0, sizeof(frq[0]) * (unsigned long)(n));
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