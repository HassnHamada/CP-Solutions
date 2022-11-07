#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 14, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

// bitset<N> dp;

// void pre()
// {
//     for (int i = 3; i < N; i++)
//     {
//         for (int j = 1; j < (i + 1) / 2; j++)
//         {
//             if (dp[j] == dp[i - j])
//             {
//                 dp[i] = 1;
//                 break;
//             }
//         }
//     }
// }

map<int, bool> dp;

bool win(int n, bool p = true, bool t = true)
{
    if (n <= 2)
    {
        return !p;
    }
    int k = (((n << 1) | p) << 1) | t;
    if (dp.find(k) != dp.end())
    {
        return dp[k];
    }
    for (int j = 1; j < (n + 1) / 2; j++)
    {
        if ((win(j, !p, !t) == p && win(n - j, !p, !t) == p) ||
            (win(j, !p, t) != p && win(n - j, p, t) == p) ||
            (win(n - j, !p, t) != p && win(j, p, t) == p))
        {
            return dp[k] = p;
        }
    }
    return dp[k] = !p;
}

void run()
{
    // int n;
    // scanf("%d", &n);
    for (int i = 1; i < N; i++)
    {
        cout << i << " " << win(i) << endl;
    }
    // win(10);
    // printf(n >= N || dp[n] ? "first\n" : "second\n");
}

int main()
{
    // pre();
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}