#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 100, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

ll arr[N], ans[N];

void run()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", n & 1 ? (n == 3 ? 5 : 3) : 7);
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