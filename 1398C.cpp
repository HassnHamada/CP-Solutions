#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char arr[N];
int acc[N];
map<int, int> cnt;

void run()
{
    int n;
    scanf("%d%s", &n, arr);
    for (int i = 0; i < n; i++)
    {
        acc[i] = (arr[i] -= '1');
    }
    for (int i = 1; i < n; i++)
    {
        acc[i] += acc[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        cnt[acc[i]]++;
    }
    ll ans = 0;
    for (int i = 0, t = 0; i < n; t += arr[i++])
    {
        ans += cnt[t];
        cnt[acc[i]]--;
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