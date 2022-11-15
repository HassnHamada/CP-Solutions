#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 3, L = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

ll calc(int num, int mx)
{
    vector<int> fct;
    for (int i = 2; 1ll * i * i <= num; i++)
    {
        if (num % i == 0)
        {
            fct.push_back(i);
            while (num % i == 0)
            {
                num /= i;
            }
        }
    }
    if (num > 1)
    {
        fct.push_back(num);
    }
    ll ans = 0;
    int sz = fct.size();
    // cout << "------ " << sz << endl;
    for (int i = 0; i < (1 << sz); i++)
    {
        int lcm = 1;
        for (int j = 0; j < sz; j++)
        {
            if ((i >> j) & 1)
            {
                lcm *= fct[j];
            }
        }
        if (__builtin_popcount(i) % 2)
        {
            ans -= mx / lcm;
        }
        else
        {
            ans += mx / lcm;
        }
    }
    return ans;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] % arr[i])
        {
            ans = 0;
            break;
        }
        else if (arr[i - 1] == arr[i])
        {
            ans = 1ll * ans * (m / arr[i]) % MOD;
        }
        else
        {
            ans = ans * calc(arr[i - 1] / arr[i], m / arr[i]) % MOD;
        }
    }
    printf("%d\n", ans % MOD);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}