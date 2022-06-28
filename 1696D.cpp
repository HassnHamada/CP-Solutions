#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 5e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int n, arr[N];
// pair<int, int> nxtb[N], nxts[N];

// int get_nxtb(int ii)
// {
//     int ret = max(ii, nxtb[ii].first);
//     for (int i = max(ii + 1, nxtb[ii].second); i < n; i++)
//     {
//         if (arr[i] < arr[ii])
//         {
//             break;
//         }
//         if (arr[i] > arr[ret])
//         {
//             ret = i;
//         }
//         else
//         {
//             if (nxts[ret].first == -1 || arr[nxts[ret].first] > arr[i])
//             {
//                 nxts[ret].first = i;
//             }
//         }
//         nxts[ret].second = i;
//     }
//     return nxtb[ii].first = nxtb[ii].second = ret;
// }

// int get_nxts(int ii)
// {
//     int ret = max(ii, nxtb[ii].first);
//     for (int i = max(ii + 1, nxtb[ii].second); i < n; i++)
//     {
//         if (arr[i] > arr[ii])
//         {
//             break;
//         }
//         if (arr[i] < arr[ret])
//         {
//             ret = i;
//         }
//         else
//         {
//             if (nxtb[ret].first == -1 || arr[nxtb[ret].first] < arr[i])
//             {
//                 nxtb[ret].first = i;
//             }
//         }
//         nxtb[ret].second = i;
//     }
//     return nxts[ii].first = nxts[ii].second = ret;
// }

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        // nxtb[i].first = nxtb[i].second = nxts[i].first = nxts[i].second = -1;
    }
    queue<pair<int, int>> q1, q2;
    q1.push({arr[0], 0});
    q2.push({arr[0], 0});
    for (int i = 1; i < n; i++)
    {
        // if ()
    }

    int ans = 0, ii = 0;
    // while (ii != n - 1)
    // {
    //     ii = max(get_nxtb(ii), get_nxts(ii));
    //     ans += 1;
    // }
    printf("%d\n", ans);
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
