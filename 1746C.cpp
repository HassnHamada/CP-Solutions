#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

// struct DT
// {
//     int v, i;
//     DT(int _v, int _i)
//     {
//         v = _v;
//         i = _i;
//     }
//     bool operator<(const DT &other) const
//     {
//         return v < other.v;
//     }
// };

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    multiset<pair<int, int>> srt;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            srt.emplace(arr[i] - arr[i + 1], i + 2);
        }
    }
    // sort(srt.begin(), srt.end());
    // vector<int> ans;
    // for (auto &&[v, i] : srt)
    // {
    //     if (v > n - (int)ans.size())
    //     {
    //         break;
    //     }
    //     for (int j = 0; j < v; j++)
    //     {
    //         ans.push_back(i);
    //     }
    // }
    // assert((int)ans.size() <= n);
    vector<int> ans;
    for (int j = 1; j <= n && !srt.empty(); j++)
    {
        auto t = *srt.begin();
        srt.erase(srt.begin());
        int v = t.first, i = t.second;
        ans.push_back(i);
        if (v > j)
        {
            srt.emplace(v - j, i);
        }
    }

    while ((int)ans.size() < n)
    {
        ans.push_back(1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
