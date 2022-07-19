#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10, M = 18, L = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], n;
bool usd[N];

bool dfs(int cn = 0)
{
    if (cn == n)
    {
        // cout << "ok " << cn + 1 << endl;
        return true;
    }
    // cout << "IN " << cn << endl;
    // for (int i = 1; i <= n; i++)
    int l = arr[cn] ? (cn + 1) / arr[cn] : cn + 2, r = arr[cn] ? l + cn - 1 : n;
    for (int i = l; i <= r; i++)
    {
        // cout << cn << " " <<
        cout << i << " " << (cn + 1) / i << " " << arr[cn] << " " << usd[i] << endl;
        if ((cn + 1) / i == arr[cn] && !usd[i])
        {
            usd[i] = true;
            // cout << "to " << cn + 1 << " usd " << i << endl;
            if (dfs(cn + 1))
            {
                arr[cn] = i;
                // cout << "ok " << cn << endl;
                return true;
            }
            usd[i] = false;
        }
    }
    // cout << "fail " << cn << endl;
    return false;
}

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    assert(dfs());
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", arr[i] + 1, " \n"[i + 1 == n]);
    }
    memset(usd, 0, sizeof(usd[0]) * (n + 1));
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
