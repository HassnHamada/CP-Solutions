#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n;
    scanf("%d", &n);
    map<int, vector<int>> nums;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        if (nums.find(v) == nums.end())
        {
            nums.emplace(v, vector<int>());
        }
        nums[v].push_back(i + 1);
    }
    vector<pair<int, int>> ans;
    while (nums.size() != 1)
    {
        auto it = nums.rbegin();
        int v = it->first;
        vector<int> &vec = it->second;
        int w = (++it)->first;
        assert(v > w);
        int x = (v + w - 1) / w;
        if (x == v)
        {
            printf("-1\n");
            return;
        }
        for (auto &&i : vec)
        {
            ans.emplace_back(i, *it->second.begin());
        }
        if (nums.find(x) == nums.end())
        {
            nums.emplace(x, vec);
        }
        else
        {
            nums[x].insert(nums[x].end(), vec.begin(), vec.end());
        }
        nums.erase(nums.find(v));
    }
    printf("%d\n", (int)ans.size());
    for (auto &&[i, j] : ans)
    {
        printf("%d %d\n", i, j);
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}