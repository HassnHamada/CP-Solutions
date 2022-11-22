#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

ll acc[N];

void run()
{
    int n;
    scanf("%d", &n);
    // cout << n << " ---------\n";
    vector<int> z_pos;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", acc + i);
        if (acc[i] == 0)
        {
            z_pos.push_back(i);
        }
        acc[i] += acc[i - 1];
    }
    z_pos.push_back(n + 1);
    int ans = count(acc + 1, acc + z_pos[0], 0);
    for (int i = 0, m = z_pos.size(); i < m - 1; i++)
    {
        map<ll, int> frq;
        for (int j = z_pos[i]; j < z_pos[i + 1]; j++)
        {
            frq[acc[j]]++;
        }
        assert(!frq.empty());
        auto res = *max_element(frq.begin(), frq.end(), [](const auto &x, const auto &y)
                                { return x.second < y.second; });
        ans += res.second;
        // cout << z_pos[i] << " " << z_pos[i + 1] << " " << res.first << " " << res.second << endl;
    }
    printf("%d\n", ans);
    // cout << n << " ^^^^^^^^^\n";
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
