#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char arr[N];

void run()
{
    scanf("%s", arr);
    ll ans = 0;
    for (int i = 0, o = 0; arr[i]; i++)
    {
        o += arr[i] == '1';
        if (arr[i] == '0' && o)
        {
            ans += o + 1;
        }
    }
    printf("%lld\n", ans);
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