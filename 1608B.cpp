#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
ll arr[N];

void run()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    bool ok = (abs(a - b) <= 1) && (a + b <= n - 2);
    if (ok)
    {
        vector<int> ans(a + b + 1);
        if (a >= b)
        {
            ans[0] = 1;
            for (int i = 0; i < a; i++)
            {
                ans[2 * i + 1] = n - i;
            }
            for (int i = 0; i < b; i++)
            {
                ans[2 * i + 2] = i + 2;
            }
            if (a == 0)
            {
                for (int i = 2; i <= n; i++)
                {
                    ans.push_back(i);
                }
            }
            else
            {
                if (ans[a + b] < n - a)
                {
                    for (int i = b + 2; i <= n - a; i++)
                    {
                        ans.push_back(i);
                    }
                }
                else
                {
                    for (int i = n - a; i >= b + 2; i--)
                    {
                        ans.push_back(i);
                    }
                }
            }
        }
        else
        {
            ans[0] = n;
            for (int i = 0; i < b; i++)
            {
                ans[2 * i + 1] = i + 1;
            }
            for (int i = 0; i < a; i++)
            {
                ans[2 * i + 2] = n - i - 1;
            }
            for (int i = b + 1; i < n - a; i++)
            {
                ans.push_back(i);
            }
        }
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
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
