#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e5 + 10;
int arr[2][N], pre[N], suf[N], ans[N];

void run()
{
    int m;
    cin >> m;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    pre[0] = arr[1][0];
    for (int i = 1; i < m; i++)
    {
        pre[i] = pre[i - 1] + arr[1][i];
    }
    suf[m] = 0;
    for (int i = m - 1; ~i; i--)
    {
        ans[i] = max(i ? pre[i - 1] : 0, suf[i + 1]);
        suf[i] = suf[i + 1] + arr[0][i];
    }
    // for (int i = 0; i < m; i++)
    // {
    //     cout << ans[i] << " \n"[i + 1 == m];
    // }
    cout << *min_element(ans, ans + m) << endl;
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
