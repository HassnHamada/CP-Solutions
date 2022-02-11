#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

void run()
{
    int n, h, arr[3] = {0, 0, 0};
    cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[0];
        sort(arr, arr + 3);
    }
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    int q = h / (arr[1] + arr[2]), r = h % (arr[1] + arr[2]);
    assert(q * (arr[1] + arr[2]) + r == h);
    cout << q * 2 + (r ? (r / arr[2] ? 2 : 1) : 0) << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
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
