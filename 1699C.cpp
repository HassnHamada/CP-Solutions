#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[N];
ll fact[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int ans = 1;
    set<int> sss;
    for (int i = 1, m = (arr[0] == 0 ? 1 : 0), l = 0; i < n; i++)
    {
        if (arr[i] == m)
        {
            if (l)
            {
                ans = ans * fact[l] % MOD;
                ans = (((ll)(sss.size() - l) * l * ans) + ans) % MOD;
            }
            m += 1;
            while (m == arr[0] || sss.find(m) != sss.end())
            {
                sss.erase(m++);
            }
            l = 0;
        }
        else
        {
            sss.insert(arr[i]);
            l += 1;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }

    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}