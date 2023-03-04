#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10, M = 21, L = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

std::vector<int> prime;
bool is_composite[N];

void linear_sieve(int n = N)
{
    std::fill(is_composite, is_composite + n, false);
    for (int i = 2; i < n; ++i)
    {
        if (!is_composite[i])
            prime.push_back(i);
        for (int j = 0; j < (int)prime.size() && i * prime[j] < n; ++j)
        {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int arr[N];

// ll solve(int p, int np)
// {
//     cout << p << " " << np << endl;
//     if (p == 0 && np == 0)
//     {
//         return 1;
//     }
//     if (p <= 0 || np < 0)
//     {
//         return 0;
//     }
//     assert((p + np) % 2 == 0);
//     return (np + p - 1) * max(solve(p - 1, np - 1), solve(p - 2, np));
// }

vector<int> p, np;

ll solve_2(int i = 0, int j = 0, int k = 0)
{
    cout << "in " << i << " " << j << " " << k << endl;
    if (i == (int)p.size() && j == (int)np.size())
    {
        cout << "out a " << (k == 0) << endl;
        return k == 0;
    }
    if (i >= (int)p.size() || j > (int)np.size())
    {
        cout << "out b 0" << endl;
        return 0;
    }
    ll ret = solve_2(i + 1, j, k + 1) + k * (solve_2(i + 1, j, k - 1) + solve_2(i, j + 1, k - 1));
    cout << "out c " << ret << endl;
    return ret;
}

void run()
{
    // int n, p = 0;
    int n;
    scanf("%d", &n);
    linear_sieve();
    for (int i = 0; i < 2 * n; i++)
    {
        scanf("%d", arr + i);
        if (is_composite[arr[i]] || arr[i] == 1)
        {
            np.push_back(arr[i]);
        }
        else
        {
            p.push_back(arr[i]);
            // p++;
        }
    }
    sort(p.begin(), p.end());
    sort(np.begin(), np.end());
    cout << solve_2() << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         if ((i + j) % 2 == 0)
    //         {
    //             cout << solve(i, j) << "\t";
    //         }
    //         else
    //         {
    //             cout << "n\t";
    //         }
    //     }
    //     cout << endl;
    // }

    // for (int i = 0, j = 0; i < n; i++)
    // {
    //     while (arr[j] < (i - j + 1))
    //     {
    //         j++;
    //     }
    //     printf("%d%c", i - j + 1, " \n"[i + 1 == n]);
    // }
}

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