#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 5e2 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

void run()
{
    int n, s = 0;
    scanf("%d", &n);
    std::vector<std::vector<int>> inp(n);
    std::vector<int> nums;
    for (auto &&i : inp)
    {
        int k;
        scanf("%d", &k);
        i.resize(k);
        for (auto &&j : i)
        {
            scanf("%d", &j);
            nums.push_back(j);
        }
    }
    std::sort(nums.begin(), nums.end());
    for (auto &&i : inp)
    {
        for (auto &&j : i)
        {
            j = std::lower_bound(nums.begin(), nums.end(), j) - nums.begin();
        }
    }
    for (auto &&i : inp)
    {
        for (int j = 0, m = i.size(); j < m - 1; j++)
        {
            if (i[j] + 1 != i[j + 1])
            {
                s += 1;
            }
        }
    }
    printf("%d %d\n", s, n + s - 1);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}