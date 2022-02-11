#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1 << 4;
bool arr[N];

bool ok()
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i])
        {
            for (int j = 0; j < N; j++)
            {
                if (j & i || !arr[j])
                {
                    continue;
                }
                return true;
            }
        }
    }
    return false;
}

void run()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int m = 0;
        for (int j = 0, v; j < k; j++)
        {
            cin >> v;
            m |= v << j;
        }
        assert(m >= 0 && m < N);
        arr[m] = true;
    }
    cout << (ok() ? "YES\n" : "No\n");
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
