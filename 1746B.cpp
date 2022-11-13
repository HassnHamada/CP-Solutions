#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int ii = 0, jj = n - 1, ans = 0;
    while (ii < jj)
    {
        while (ii < n && arr[ii] == 0)
        {
            ii++;
        }
        while (jj >= 0 && arr[jj] == 1)
        {
            jj--;
        }
        if (ii < jj)
        {
            // assert(arr[ii] == 1);
            // assert(arr[jj] == 0);
            swap(arr[ii], arr[jj]);
            ans++;
        }
    }
    // assert(is_sorted(arr, arr + n));
    printf("%d\n", ans);
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
