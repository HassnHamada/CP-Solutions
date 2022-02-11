#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 100, K = 1e6 + 10;
// int arr[N],;
double pro[N][K];

void run()
{
    int n, m, k, e = 0;
    cin >> n >> m >> k;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        if (v <= m)
        {
            pro[i][0] = 1;
            e += 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            pro[i][j] = (e + pro[i][j - 1] * n * (n - 1) / 2) / (n * (n + 1) / 2);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << pro[i][k] << " \n"[i == n - 1];
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10) << fixed;
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
