#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 20;
int n, x, arr[N];
pair<int, int> best[1 << N];


int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    best[0] = {1, 0};
    for (int i = 1; i < (1 << n); i++)
    {
        best[i] = {n + 1, 0};
        for (int j = i, k = i & -i, l = __builtin_popcount(k - 1); j; j -= k, k = j & -j, l = __builtin_popcount(k - 1))
        {
            auto p = best[i ^ k];
            if (p.second + arr[l] <= x)
            {
                p.second += arr[l];
            }
            else
            {
                p.first += 1;
                p.second = arr[l];
            }
            best[i] = min(best[i], p);
        }
    }
    printf("%d\n", best[(1 << n) - 1].first);
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
