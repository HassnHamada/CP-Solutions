#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 4, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    // Input
    // line 1 : n size of permutation 1 <= n <= 1e6
    // line 2 : n distinct number 1 <= ai <= n
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    pair<int, int> ans = {0, INF};
    for (int i = 0; i < n; i++)
    {
        int tem = 0;
        for (int j = i; j < n; j++)
        {
            tem ^= arr[j];
            if ((j - i) & 1)
            {
                ans.first = max(ans.first, tem);
                ans.second = min(ans.second, tem);
                // for (int k = i; k <= j; k++)
                // {
                //     cout << arr[k] << " ";
                // }
                // cout << ans << endl;
            }
        }
    }

    printf("%d %d\n", ans.first, ans.second);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_ok.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}