#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

struct DT
{
    int c, o;
    bool operator<(const DT &other) const
    {
        return c < other.c;
    }
    bool operator>(const DT &other) const
    {
        return c > other.c;
    }
} arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].o);
        assert(arr[i].c < (1 << M));
    }
    int ans = 0;
    for (int i = M, sz = 0; i && sz < n; i--)
    {
        for (int j = M - i; j < n; j++)
        {
            arr[j].c = (arr[j].o ^ ans) & arr[j].o;
        }
        sort(arr + sz, arr + n, greater<DT>());
        // cout << i << " " << ans << " " << arr[sz].c << endl;
        assert((ans | arr[sz].c) == (ans | arr[sz].o));
        ans |= arr[sz++].c;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", arr[i].o, " \n"[i + 1 == n]);
    }
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
