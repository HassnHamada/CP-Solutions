#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[M];

void run()
{
    int n;
    scanf("%d", &n);
    str[4] = str[6] = '_';
    str[5] = str[8] = '\0';
    map<string, ll> mmm;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        str[3] = str[0];
        str[7] = str[1];
        mmm[str] += 1;
        mmm[str + 3] += 1;
        mmm[str + 6] += 1;
    }
    ll ans = 0;
    for (auto &&j : mmm)
    {
        if (j.first.find('_') == string::npos)
        {
            str[3] = j.first[0];
            str[7] = j.first[1];
            ll v = j.second * (mmm[str + 3] + mmm[str + 6] - 2 * j.second);
            assert(v >= 0);
            ans += v;
            mmm[str + 3] -= j.second;
            mmm[str + 6] -= j.second;
        }
    }
    printf("%lld\n", ans);
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