#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10, M = 20;
int suc[M][N], len[N];
bool vis[N];

void dfs(int n)
{
    if (!vis[n])
    {
        vis[n] = true;
        dfs(suc[0][n]);
        len[n] = len[suc[0][n]] + 1;
    }
}

int lift(int n, int d)
{
    if (d <= 0)
    {
        return n;
    }
    int i = 0;
    while (d)
    {
        if (d & 1)
        {
            n = suc[i][n];
        }
        d >>= 1;
        i += 1;
    }
    return n;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> suc[0][i];
    }
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            suc[i][j] = suc[i - 1][suc[i - 1][j]];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int c = lift(a, len[a]);
        if (lift(a, len[a] - len[b]) == b)
        {
            cout << len[a] - len[b] << endl;
        }
        else if (lift(c, len[c] - len[b]) == b)
        {
            cout << len[a] + len[c] - len[b] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
