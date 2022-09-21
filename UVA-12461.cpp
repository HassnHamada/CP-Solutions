#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

// bool vis[N];

// pair<int, int> solve(int cn, int n)
// {
//     if (cn + 1 == n)
//     {
//         return {!vis[cn], vis[cn]};
//     }
//     pair<int, int> ret = {0, 0};
//     if (vis[cn])
//     {
//         for (int i = 0; i < n; i++)
//         {
//             if (vis[i])
//             {
//                 continue;
//             }
//             vis[i] = true;
//             auto res = solve(cn + 1, n);
//             vis[i] = false;
//             ret.first += res.first;
//             ret.second += res.second;
//         }
//     }
//     else
//     {
//         vis[cn] = true;
//         auto res = solve(cn + 1, n);
//         vis[cn] = false;
//         ret.first += res.first;
//         ret.second += res.second;
//     }
//     return ret;
// }

void run()
{
    while (true)
    {
        int n;
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        // pair<int, int> ans = {0, 0};
        // for (int i = 0; i < n; i++)
        // {
        //     vis[i] = true;
        //     auto res = solve(1, n);
        //     vis[i] = false;
        //     ans.first += res.first;
        //     ans.second += res.second;
        // }
        printf("1/2\n");
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}