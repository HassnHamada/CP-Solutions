#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    int mx = 0, f = -1, l = 0;
    for (int i = 1, v; i <= n; i++)
    {
        scanf("%d", &v);
        if (v == 0)
        {
            if (f == -1)
            {
                f = l;
            }
            mx = max(mx, l);
            l = 0;
        }
        else
        {
            l += 1;
        }
        // cout << mx << " " << f << " " << l << endl;
    }
    mx = max(mx, f + l);
    printf("%d\n", mx);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
