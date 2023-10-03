#include <bits/stdc++.h>
// #include <stdio.h>
using namespace std;
typedef long long ll;

void run()
{
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);
    if (x >= k - 1 && n >= k)
    {
        int ans = k * (k - 1) / 2 + (n - k) * (x - (x == k));
        printf("%d\n", ans);
    }
    else
    {
        printf("-1\n");
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