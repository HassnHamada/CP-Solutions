#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 2e3 + 10;
bitset<N> str;

void run()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    for (int i = 1; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < i; j++)
        {
            for (int k = i + j; k < n; k += i)
            {
                c += str[j] != str[k];
            }
        }
        if (c == x)
        {
            cout << c << endl;
        }
    }
    cout << n << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("triangles.in", "r", stdin);
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
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