#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e6 + 10;
ll arr[N], srt[N], frq[N];

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);

    ll n;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", srt + i);
        arr[i] = srt[i];
    }
    sort(srt, srt + n);
    ll nn = unique(srt, srt + n) - srt;
    for (int i = 0; i < n; i++)
    {
        frq[lower_bound(srt, srt + nn, arr[i]) - srt]++;
    }
    ll ans = -1, acc = 0;
    for (int i = 0; i < nn; i++)
    {
        acc += frq[i];
        if (acc % 3 == 0)
        {
            ans = srt[i];
        }
    }
    printf("%lld\n", ans);

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}