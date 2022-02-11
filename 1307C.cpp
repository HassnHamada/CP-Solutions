#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 26;
ll arr[N], arr2[N][N];

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    for (auto &&i : s)
    {
        int j = i - 'a';
        for (int k = 0; k < 26; k++)
        {
            arr2[k][j] += arr[k];
        }
        arr[j] += 1;
    }
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, arr[i]);
        for (int j = 0; j < N; j++)
        {
            ans = max(ans, arr2[i][j]);
        }
    }
    cout << ans << endl;
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
