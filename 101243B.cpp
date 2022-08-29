#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 3, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[M];

ll calc(int x, int y, int z, int n)
{
    if (n > 0)
    {
        ll ret = calc(x, z, y, n - 1);
        if (arr[0] == arr[1] && arr[0] == arr[2])
        {
            return ret;
        }
        arr[x] -= 1;
        arr[y] += 1;
        ret += 1;
        if (arr[0] == arr[1] && arr[0] == arr[2])
        {
            return ret;
        }
        return ret + calc(z, y, x, n - 1);
    }
    return 0;
}

void test()
{
    for (int i = 3; i <= 3 * 20; i += 3)
    {
        arr[0] = i;
        arr[1] = arr[2] = 0;
        ll res = calc(0, 1, 2, i);
        ll res2 = (1ll << (i / 3 * 2 - 1)) + ((1ll << ((i + 5) / 6 * 2 - 1)) - (i % 6 ? 2 : 1));
        cout << res << " " << res2 << endl;
        assert(res == res2);
        // printf("%lld\n", res);
        // ll v = log2(res), w = res - (1ll << v);
        // printf("%lld %lld\n", 1ll << v, w);
    }
}

void run()
{
    int n;
    scanf("%d\n", &n);
    printf("%lld\n", (1ll << (n / 3 * 2 - 1)) + ((1ll << ((n + 5) / 6 * 2 - 1)) - (n % 6 ? 2 : 1)));
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
