#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, L = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int m = 0;
    while (m < n && arr[m] == 0)
    {
        m += 1;
    }
    while (m < n--)
    {
        if (m && arr[m] != 0)
        {
            m -= 1;
        }
        for (int i = m; i < n; i++)
        {
            arr[i] = arr[i + 1] - arr[i];
        }
        sort(arr + m, arr + n);
        while (m < n && arr[m] == 0)
        {
            m += 1;
        }
    }
    printf("%d\n", arr[0]);
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
