#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 0e5 + 10, M = 448, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
char grd[N][N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)grd[i]);
    }
    vector<bool> vec0(n, false);
    for (int i = 1; i < n; i++)
    {
        vec0[i] = vec0[i - 1];
        for (int j = 0; !vec0[i] && j < m; j++)
        {
            vec0[i] = grd[i - 1][j] == 'R';
        }
    }
    vector<bool> vec1(m, false);
    for (int i = 1; i < m; i++)
    {
        vec1[i] = vec1[i - 1];
        for (int j = 0; !vec1[i] && j < n; j++)
        {
            vec1[i] = grd[j][i - 1] == 'R';
        }
    }
    // for (auto &&i : vec0)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto &&i : vec1)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ok |= grd[i][j] == 'R' && !vec0[i] && !vec1[j];
        }
    }
    printf(ok ? "YES\n" : "NO\n");
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