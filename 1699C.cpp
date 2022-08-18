#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[N], pos[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        pos[arr[i]] = i;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << pos[i] << " ";
    // }
    // cout << endl;
    int ans = 1;
    for (int i = 1, l = pos[0], r = l; i < n; i++)
    {
        if (pos[i] < l)
        {
            l = pos[i];
        }
        else if (pos[i] > r)
        {
            r = pos[i];
        }
        else
        {
            ans = ans * (r - l + 1ll - i) % MOD;
        }
    }
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