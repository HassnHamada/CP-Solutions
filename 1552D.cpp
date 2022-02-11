#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;
const int N = 10;
int arr[N], n;

bool dfs(int c, vector<int> &ans)
{
    if (c == n)
    {
        return set<int>(ans.begin(), ans.end()).size() <= n;
    }
    for (auto &&i : ans)
    {
        ans.push_back(i - arr[c]);
        if (dfs(c + 1, ans))
        {
            return true;
        }
        ans.pop_back();
        ans.push_back(arr[c] + i);
        if (dfs(c + 1, ans))
        {
            return true;
        }
        ans.pop_back();
    }
    return false;
}

void run()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    ans.push_back(0);
    cout << (dfs(0, ans) ? "YES\n" : "NO\n");
    // if (ans.size() >= n)
    // {
    //     sort(ans.begin(), ans.end());
    //     int m = unique(ans.begin(), ans.end()) - ans.begin();
    //     for (int i = 0; i < n; i++)
    //     {
    //         cout << (i < m ? ans[i] : 0) << " \n"[i + 1 == n];
    //     }
    // }
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
