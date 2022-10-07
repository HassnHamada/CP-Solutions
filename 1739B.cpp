#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 3, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], ans[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    bool ok = true;
    ans[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int v1 = ans[i - 1] - arr[i], v2 = arr[i] + ans[i - 1];
        if (v1 != v2 && v1 >= 0 && v2 >= 0)
        {
            ok = false;
            break;
        }
        else
        {
            assert(v1 == v2 || (v2 >= 0 && v1 < 0));
            ans[i] = v2;
        }
    }
    if (ok)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", ans[i], " \n"[i + 1 == n]);
        }
    }
    else
    {
        printf("-1\n");
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
