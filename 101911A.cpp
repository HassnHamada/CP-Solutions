#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10;
int arr[N];

void run()
{
    int n, m, d;
    cin >> n >> m >> d;
    set<int> sss;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sss.insert(arr[i]);
        // mmm.insert({arr[i], 0});
        // cin >> sss;
    }
    int ans = 0;
    map<int, int> mmm;
    while (sss.size())
    {
        ans += 1;
        int t = 1;
        while (sss.size())
        {
            auto it = sss.lower_bound(t);
            if (it == sss.end())
            {
                break;
            }
            // ans.back().push_back(*it);
            mmm.emplace(*it, ans);
            // mmm[*it] = ans;
            // cout << sss.size() << " " << (*it) << endl;
            t = *it + d + 1;
            sss.erase(it);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        assert(mmm.find(arr[i]) != mmm.end());
        cout << mmm[arr[i]] << " \n"[i + 1 == n];
    }

    // for (auto &&i : sss)
    // {
    //     cout << i << endl;
    // }
}

// void pre()
// {
// }

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    // pre();
    int test = 1;
    // cin >> test;
    while (test--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}