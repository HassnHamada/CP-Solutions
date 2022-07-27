#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 26, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    bool ok = true;
    for (int i = 0, j = -1, s = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        if (j == -1 || v == j + 1)
        {
            j = v;
        }
        else if (v == j + 2)
        {
            if (s == 0 || s == 1)
            {
                j = v;
                s = s == 1 ? -1 : 1;
            }
            else
            {
                ok = false;
            }
        }
        else if (v == j + 3)
        {
            if (s == 0)
            {
                j = v;
                s = -1;
            }
            else
            {
                ok = false;
            }
        }
        else
        {
            ok = false;
        }
        // cout << i << " " << ok << endl;
    }
    // printf("%d\n", ans);
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