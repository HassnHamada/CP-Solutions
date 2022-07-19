#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    bool ok = true;
    for (int i = 1; ok && i <= n; i++)
    {
        arr[i] = (l + i - 1) / i * i;
        assert(arr[i] >= l);
        assert(arr[i] - i < l);
        assert(gcd(arr[i], i) == i);
        if (arr[i] > r)
        {
            ok = false;
        }
        // scanf("%d", arr + i);
    }
    if (ok)
    {
        printf("YES\n");
        for (int i = 1; i <= n; i++)
        {
            printf("%d%c", arr[i], " \n"[i == n]);
        }
    }
    else
    {
        printf("NO\n");
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