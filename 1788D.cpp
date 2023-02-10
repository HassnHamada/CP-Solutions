#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 1e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int arr[N];

int solve(vector<int> &vec, int n)
{
    int p = 1, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i + 1 < n && vec[i + 1] - vec[i] < vec[i] - vec[i - 1])
        {
            // r++;
            // l = 0;
            p = 1;
        }
        else
        {
            if (p)
            {
                r++;
                p = 0;
            }
        }
    }
    return r;
}

void run()
{
    int n = 0;
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 2; i <= n; i++)
    {
        int v = 0;
        for (int j = (1 << i) - 1; j < (1 << n); j += (j & (-j)))
        {
            if (__builtin_popcount(j) != i)
            {
                assert(__builtin_popcount(j) < i);
                j += (1 << (i - __builtin_popcount(j))) - 1;
            }
            assert(__builtin_popcount(j) == i);
            vector<int> tem;
            for (int k = 0; k < n; k++)
            {
                if (j & (1 << k))
                {
                    tem.push_back(arr[k]);
                    // cout << k << " " << arr[k] << " ";
                    cout << arr[k] << " ";
                }
            }
            cout << endl;
            int ret = solve(tem, i);
            cout << ret << endl;
            ans = (ans + ret) % MOD;
            v = (v + ret) % MOD;
        }
        cout << i << " " << v << endl;
    }
    cout << ans << endl;
    ;
}

// 0011
// 0101
// 0110
// 1001
// 1010
// 1100

// 00111
// 01011
// 01101
// 01110
// 10011
// 10101
// 10110
// 11001
// 11010
// 11100

int main()
{
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}

// r l l l
// 1 3 5 11 15
// 1 3 5 11 15
// r l l r l
//  2 2 6  4