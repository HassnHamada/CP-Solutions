#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;


int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);

    int n, ans = 0;
    set<int, greater<int>> sss;
    sss.insert(15);
    sss.insert(12);
    for (int i = 1; i < 11; i++)
    {
        sss.insert(i);
    }
    vector<int> vec(20);
    cin >> n;
    while (n)
    {
        int t = *sss.lower_bound(n);
        vec[t] = n / t;
        ans += vec[t];
        n %= t;
    }
    cout << ans << endl;
    for (int i = 19; ~i; i--)
    {
        if (vec[i] == 0)
        {
            continue;
        }
        else if (i == 15)
        {
            for (int j = 0; j < vec[i]; j++)
            {
                cout << 1 << " ";
            }
        }
        else if (i == 12)
        {
            for (int j = 0; j < vec[i]; j++)
            {
                cout << 2 << " ";
            }
        }
        else if (i <= 10 && i >= 0)
        {
            // 10 -> 3
            // 9 -> 4
            // .
            // .
            // .
            // 1 -> 12
            for (int j = 0; j < vec[i]; j++)
            {
                cout << 13 - i << " ";
            }
        }
        else
        {
            assert(false);
        }
    }
    cout << endl;

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}