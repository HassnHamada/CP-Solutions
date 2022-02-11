#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e3 + 10;
char mat[N][N];

void run()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            // cout << c << " " << mat[i][j] << endl;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0, l = 0; j < m; j++)
        {
            if (mat[i][j] == '>')
            {
                l += 1;
            }
            else if (mat[i][j] == '<')
            {
                ans += l;
            }
            else
            {
                l = 0;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0, l = 0; j < n; j++)
        {
            // cout << i << " " << j << " " << l << endl;
            if (mat[j][i] == 'v')
            {
                l += 1;
            }
            else if (mat[j][i] == '^')
            {
                ans += l;
            }
            else
            {
                l = 0;
            }
        }
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
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

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
