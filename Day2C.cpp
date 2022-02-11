#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e5 + 10;
int arr[N], n;

void fact(int v, vector<int> &ret)
{
    for (ll i = 2; i * i <= v; i++)
    {
        if (v % i == 0)
        {
            ret.push_back(i);
            while (v % i == 0)
            {
                v /= i;
            }
        }
    }
    if (v != 1)
    {
        ret.push_back(v);
    }
}

bool ok(int v)
{
    bool ret = true;
    for (int i = 0; i < n; i++)
    {
        ret &= (arr[i] % v == 0);
    }
    return ret;
}

void run()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> vec;
    fact(arr[0], vec);
    for (auto &&i : vec)
    {
        if (ok(i))
        {
            cout << i << endl;
            return;
        }
    }
    cout << "-1\n";
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
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
