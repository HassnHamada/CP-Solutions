#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, x, cnt = 0;
    scanf("%d%d", &n, &x);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        cnt += u == x;
        cnt += v == x;
    }
    if (n == 1 || cnt == 1)
    {
        printf("Ayush\n");
    }
    else
    {
        printf(n & 1 ? "Ashish\n" : "Ayush\n");
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}