#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int n, acc[M][N];
char sss[N], ttt[N];

// bool work(int i, int j)
// {
//     // cout << i << " " << j << endl;
//     if (i == n)
//     {
//         return true;
//     }
//     if (sss[i] == ttt[i])
//     {
//         return work(i + 1, i + 1);
//     }
//     if (j < n - 1 && work(i, j + 1))
//     {
//         return true;
//     }
//     if (j >= i && j < n - 1 && ((sss[j] == 'a' && sss[j + 1] == 'b') || (sss[j] == 'b' && sss[j + 1] == 'c')))
//     {
//         swap(sss[j], sss[j + 1]);
//         if (work(i, j - 1))
//         {
//             return true;
//         }
//         swap(sss[j], sss[j + 1]);
//     }
//     return false;
// }

void run()
{
    scanf("%d%s%s", &n, sss + 1, ttt + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < M; j++)
        {
            acc[j][i] = acc[j][i - 1];
        }
        acc[sss[i] - 'a'][i] += 1;
    }
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        if (sss[i] != ttt[i])
        {
            int *it = acc[ttt[i] - 'a'];
            int j = *lower_bound(it, it + n + 1, 1);
            if (ttt[i] == 'a' || acc[(ttt[i] - 'a' + 1) % M][j] != 0)
            {
                ok = false;
            }
            else
            {
                swap(sss[i], sss[j]);
            }
        }
        acc[sss[i] - 'a'][i] -= 1;
    }

    // printf(work(0, 0) ? "YES\n" : "NO\n");
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
