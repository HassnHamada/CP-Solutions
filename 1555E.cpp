#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 3e5 + 10;
struct SEG
{
    int s, e, w;
    bool operator<(const SEG &other) const
    {
        return (this->s) < other.s;
    }
    friend bool operator<(const int &self, const SEG &other)
    {
        return self < other.s;
    }
} arr[N];
int n, m;
// vector<pair<int, int>> ans;
pair<int, int> ans;
bool vis[N];
void dfs(int cmn = 0, int cmx = 1, int mnw = INT32_MAX, int mxw = INT32_MIN)
{
    if (ans.first && mxw - mnw >= ans.second - ans.first)
    {
        return;
    }
    if (cmx == m)
    {
        // if (mxw - mnw < ans.second - ans.first || ans.first == 0)
        // {
        // }
        ans = {mnw, mxw};
        return;
    }
    int s = upper_bound(arr, arr + n, cmn) - arr,
        e = upper_bound(arr, arr + n, cmx) - arr;
    for (int i = e - 1; i >= s; i--)
    {
        if (arr[i].e <= cmx)
        {
            continue;
        }
        dfs(arr[i].s, arr[i].e, min(mnw, arr[i].w), max(mxw, arr[i].w));
    }
}

void run()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].s >> arr[i].e >> arr[i].w;
    }
    sort(arr, arr + n);
    dfs();
    // assert(!ans.empty());
    // sort(ans.begin(), ans.end(), [](const pair<int, int> &p1, const pair<int, int> &p2)
    //      { return p1.second - p1.first < p2.second - p2.first; });
    // for (auto &&i : ans)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    // cout << ans[0].second - ans[0].first << endl;
    cout << ans.second - ans.first << endl;
    // cout << << endl;
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
