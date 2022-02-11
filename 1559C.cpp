#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e4 + 10;
int arr[N];

void run()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (arr[0])
    {
        cout << n + 1;
        for (int i = 0; i < n; i++)
        {
            cout << " " << i + 1;
        }
        cout << endl;
    }
    else if (!arr[n - 1])
    {
        for (int i = 0; i <= n; i++)
        {
            cout << i + 1 << " \n"[i == n];
        }
    }
    else
    {
        int i = 0;
        for (; i < n; i++)
        {
            cout << i + 1 << " ";
            if (!arr[i] && arr[i + 1])
            {
                break;
            }
        }
        cout << n + 1;
        for (i++; i < n; i++)
        {
            cout << " " << i + 1;
        }
        cout << endl;
    }
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