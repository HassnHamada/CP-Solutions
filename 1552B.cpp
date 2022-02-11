#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;
const int N = 5e4, M = 5;
int arr[N][M];

int com(int i, int j)
{
    int ret = 0;
    for (int k = 0; k < M; k++)
    {
        ret += arr[i][k] < arr[j][k];
    }
    return ret >= 3 ? i : j;
}

void run()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            // arr[j][i].second = i + 1;
        }
    }
    // vector<int> vec;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans = com(i, ans);
    }
    // sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
    {
        if (i == ans)
        {
            continue;
        }
        if (com(i, ans) != ans)
        {
            ans = -2;
            break;
        }
    }

    cout << ans + 1 << endl;
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
