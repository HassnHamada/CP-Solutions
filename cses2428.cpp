#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 2e5 + 10;
int arr[N];
map<int, int> mmm;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    ll ans = 0;
    for (int i = 0, j = 0; j < n; j++)
    {
        if (mmm.find(arr[j]) == mmm.end())
        {
            mmm.insert({arr[j], 0});
        }
        mmm[arr[j]] += 1;
        for (; mmm.size() > k; i++)
        {
            mmm[arr[i]] -= 1;
            if (mmm[arr[i]] == 0)
            {
                mmm.erase(arr[i]);
            }
        }
        ans += j - i + 1;
        // cout << ans << endl;
    }
    printf("%lld\n", ans);

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}