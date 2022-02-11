#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 10;
char grd[N][N << 1];
int n, m;

bool ok(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && (grd[i][j] == '*' || grd[i][j] == '#');
}

bool setGrd(int i, int jl, int jr, int k)
{
    // cout << i << " " << jl << " " << jr << " " << k << endl;
    // cout << ok(i - 1, jl - 1) << " " << ok(i - 1, jr + 1) << endl;
    if (ok(i - 1, jl - 1) && ok(i - 1, jr + 1))
    {
        // cout << "IN\n";
        if (setGrd(i - 1, jl - 1, jr + 1, k - 1))
        {
            grd[i][jl] = grd[i][jr] = '#';
            return true;
        }
    }
    if (k <= 0)
    {
        grd[i][jl] = grd[i][jr] = '#';
        return true;
    }
    return false;
}

void run()
{
    int k;
    cin >> n >> m >> k;
    // cout << n << " " << m << " " << k << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grd[i][j];
        }
    }
    for (int i = n - 1; ~i; i--)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << i << " " << j << endl;
            if (ok(i, j))
            {
                setGrd(i, j, j, k);
            }
        }
    }
    // cout << n << " " << m << endl;
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << j << " " << m << endl;
            // cout << grd[i][j];
            ans &= (grd[i][j] == '#' || grd[i][j] == '.');
        }
        // cout << endl;
    }
    cout << (ans ? "YES\n" : "NO\n");
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
