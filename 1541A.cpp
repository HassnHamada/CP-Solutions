#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

// const int N = 1e5 + 10;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 2)
        {
            cout << "2 1";
        }
        else if (n & 1)
        {
            cout << "3 1 2";
            n -= 3;
            for (int i = 4; n--; i++)
            {
                cout << " " << i + (i & 1 ? -1 : 1);
            }
        }
        else
        {
            for (int i = 1; n--; i++)
            {
                cout << i + (i & 1 ? 1 : -1) << " ";
            }
        }
        cout << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
