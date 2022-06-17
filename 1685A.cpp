#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[N], ans[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);
    bool ok = n % 2 == 0;
    for (int i = 1; ok && i < n / 2; i++)
    {
        ok = arr[i] != arr[n / 2 + i - 1];
    }
    for (int i = 0; ok && i < n / 2; i++)
    {
        ans[2 * i] = arr[i];
        ans[2 * i + 1] = arr[n / 2 + i];
    }

    if (ok)
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", ans[i], " \n"[i + 1 == n]);
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
