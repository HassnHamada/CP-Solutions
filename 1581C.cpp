#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 16e4 + 10;
bitset<N> grd, pat;
int n, m;

void prn(int ln, int lm)
{
    for (int i = 0; i < ln; i++)
    {
        for (int j = 0; j < lm; j++)
        {
            cout << pat[i * m + j];
        }
        cout << endl;
    }
    cout << endl;
}

void init(int ln, int lm, int s)
{
    for (int i = 0; i < ln; i++)
    {
        for (int j = 0; j < lm; j++)
        {
            pat[i * m + j + s] = 0;
        }
    }
    for (int i = 0; i < lm - 1; i++)
    {
        pat[i + s] = pat[(ln - 1) * m + i + 1 + s] = 1;
    }
    for (int i = 1; i < ln - 1; i++)
    {
        pat[i * m + s] = pat[i * m + lm - 1 + s] = 1;
    }
}

void copy(int ln, int lm, int s)
{
    for (int i = 0; i < ln; i++)
    {
        for (int j = 0; j < lm; j++)
        {
            pat[i * m + j + s] = grd[i * m + j + s];
        }
    }
}

void run()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            grd[i * m + j] = pat[i * m + j] = (c == '1');
        }
    }
    // pat = grd;
    int ans = N;
    for (int i = 5; i <= n; i++)
    {
        for (int j = 4; j <= m; j++)
        {
            for (int k = 0; k <= n - i; k++)
            {
                for (int l = 0; l <= m - j; l++)
                {
                    init(i, j, k * m + l);
                    ans = min(ans, (int)((pat ^ grd).count()));
                    copy(i, j, k * m + l);
                }
            }
        }
    }
    cout << ans << endl;
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
