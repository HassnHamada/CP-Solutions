#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e5 + 10;
ll suf[N];
// pair<int, int> arr[N];

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> suf[i];
        if (suf[i] > n - i)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = n - 2; ~i; i--)
    {
        suf[i] += suf[i + 1];
    }
    if (suf[0] < n)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        cout << max(i + 1ll, n - suf[i] + 1) << (i + 1 == m ? '\n' : ' ');
    }
    for (int i = 0; i < m; i++)
    {
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
