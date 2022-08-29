#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 24 * 60, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], vis[N], vid;

void run()
{
    vid += 1;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int ans = n - 1;
    for (; ~ans; ans--)
    {
        if (vis[arr[ans]] == vid)
        {
            break;
        }
        vis[arr[ans]] = vid;
    }
    printf("%d\n", ans + 1);
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
