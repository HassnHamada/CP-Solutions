#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e6 + 10, MOD = 1e9 + 7;
ll arr[N];

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);

    arr[1] = 2;
    for (ll i = 2, s = 1, n = 1; i < N; i++)
    {
        arr[i] = (3 * arr[i - 1] + 2 * s) % MOD;
        ll t = (s + 2 * n) % MOD;
        s = (4 * s + n) % MOD;
        n = t;
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", arr[n]);
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}