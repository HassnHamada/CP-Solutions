#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    // int z = __builtin_ctz(n);
    // int p = __builtin_popcount(n);
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> mat(n, vector<int>(m));
    for (auto &&i : mat)
    {
        for (auto &&j : i)
        {
            scanf("%d", &j);
        }
    }
    vector<int> bad;
    for (auto &&i : mat)
    {
        vector<int> srt = i;
        sort(begin(srt), end(srt));
        for (int j = 0; j < m; j++)
        {
            if (srt[j] != i[j])
            {
                bad.push_back(j);
            }
        }
        if (!bad.empty())
        {
            break;
        }
    }
    if (bad.empty())
    {
        printf("1 1\n");
    }
    else if (bad.size() > 2)
    {
        printf("-1\n");
    }
    else
    {
        assert(bad.size() == 2);
        for (auto &&i : mat)
        {
            swap(i[bad[0]], i[bad[1]]);
        }
        bool ok = true;
        for (auto &&i : mat)
        {
            for (int j = 1; j < m; j++)
            {
                if (i[j] < i[j - 1])
                {
                    ok = false;
                }
            }
        }
        if (ok)
        {
            printf("%d %d\n", bad[0] + 1, bad[1] + 1);
        }
        else
        {
            printf("-1\n");
        }
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
