#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 30;

void run()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(N, 0);
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        for (int j = 0; j < N; j++)
        {
            // cout << v << " " << j << " " << (v & (1 << j)) << endl;
            if ((v & (1 << j)) && v > vec[j])
            {
                // cout << "OK\n";
                vec[j] = v;
            }
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << vec[i] << endl;
    // }
    int ans = 0;
    for (int i = N - 1; i >= 0 && k; i--)
    {
        if (vec[i])
        {
            // cout << vec[i] << endl;
            ans |= vec[i];
            k -= 1;
        }
    }
    cout << ans << endl;
}

// cos()

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen("looking.in", "r", stdin);
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