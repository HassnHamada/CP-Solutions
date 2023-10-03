// #include <bits/stdc++.h>
#include <stdio.h>
#include <memory.h>
// #include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

int arr[N], fff[N], lll[N];
bool in[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    memset(fff, 0, sizeof(fff[0]) * (k + 1));
    memset(lll, 0, sizeof(lll[0]) * (k + 1));
    memset(in, 0, sizeof(in[0]) * (k + 1));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        if (!in[arr[i]])
        {
            fff[arr[i]] = i;
        }
        lll[arr[i]] = i + 1;
        in[arr[i]] = true;
    }
    for (int i = k - 1; i; i--)
    {
        lll[i] = max(lll[i], lll[i + 1]);
        if (fff[i + 1])
        {
            fff[i] = in[i] ? min(fff[i], fff[i + 1]) : fff[i + 1];
        }
    }
    for (int i = 1; i <= k; i++)
    {
        printf("%d%c", in[i] ? 2 * (lll[i] - fff[i]) : 0, " \n"[i == k]);
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