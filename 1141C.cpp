#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[N], ans[N];
ll acc[N];
set<int> sss;

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", arr + i);
        acc[i] += arr[i] + acc[i - 1];
    }
    bool ok = true;
    int mn = 0, mni = 0, mx = 0, mxi = 0;
    for (int i = 1; i < n; i++)
    {
        if (acc[i] == 0)
        {
            ok = false;
        }
        if (acc[i] < mn)
        {
            mni = i;
            mn = acc[i];
        }
        if (acc[i] > mx)
        {
            mxi = i;
            mx = acc[i];
        }
    }
    ok = ok && mx - mn == n - 1;
    if (ok)
    {
        ans[mxi] = n;
        for (int i = mxi - 1; i >= 0; i--)
        {
            ans[i] = ans[i + 1] - arr[i + 1];
        }
        for (int i = mxi + 1; i < n; i++)
        {
            ans[i] = ans[i - 1] + arr[i];
        }
        ok = ok && ans[mni] == 1;
    }
    for (int i = 0; ok && i < n; i++)
    {
        ok = sss.find(ans[i]) == sss.end();
        sss.insert(ans[i]);
    }
    if (ok)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", ans[i], " \n"[i + 1 == n]);
        }
    }
    else
    {
        printf("-1\n");
    }
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
