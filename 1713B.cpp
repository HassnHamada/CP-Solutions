#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 20, L = 4, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    bool ok = true;
    for (int i = 0, p = 0; ok && i < n;)
    {
        if (arr[i] < arr[n - 1])
        {
            if (arr[i] < p)
            {
                ok = false;
            }
            else
            {
                p = arr[i++];
            }
        }
        else
        {
            if (arr[n - 1] < p)
            {
                ok = false;
            }
            else
            {
                p = arr[--n];
            }
        }
    }
    printf(ok ? "YES\n" : "NO\n");
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
