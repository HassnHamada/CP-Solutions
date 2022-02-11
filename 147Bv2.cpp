// #include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;
// typedef long long int ll;

const int N = 300, EMP = 0x0f0f0f0f;
int grf[N][N], dst[N], n, m;

bool bellman(int s)
{
    memset(dst, 0x0f, sizeof(dst));
    dst[s] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int f = 0; f < n; f++)
        {
            for (int t = 0; t < n; t++)
            {
                if (grf[f][t] != EMP && dst[t] > dst[f] + grf[f][t])
                {
                    dst[t] = dst[f] + grf[f][t];
                }
            }
        }
    }
    for (int f = 0; f < n; f++)
    {
        for (int t = 0; t < n; t++)
        {
            if (grf[f][t] != EMP && dst[t] > dst[f] + grf[f][t])
            {
                return true;
            }
        }
    }
    return false;
}

void run()
{
    int n, m;
    cin >> n >> m;
    memset(grf, 0x0f, sizeof(grf));
    for (int i = 0; i < m; i++)
    {
        int f, t;
        cin >> f >> t >> grf[--f][--t] >> grf[t][f];
        grf[f][t] *= -1;
        grf[t][f] *= -1;
    }
    for (int i = 0; i < n; i++)
    {
        bellman(i)
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << (grf[i][j] == EMP ? "E" : to_string(grf[i][j]).c_str()) << " ";
    //     }
    //     cout << endl;
    // }
}

int main(int argc, char const *argv[])
{
    freopen(".\\_input.txt", "r", stdin);
    freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}