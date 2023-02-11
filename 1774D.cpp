#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

const int N = 1e2 + 10, M = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<std::vector<int>> inp(n, std::vector<int>(m));
    int sm = 0;
    std::vector<int> cnt;
    for (auto &&i : inp)
    {
        cnt.push_back(0);
        for (auto &&j : i)
        {
            scanf("%d", &j);
            cnt.back() += j;
        }
        // cnt.push_back(std::count(i.begin(), i.end(), 1));
        sm += cnt.back();
    }
    if (sm % n)
    {
        printf("-1\n");
        return;
    }
    std::vector<std::pair<int, int>> giv, tak;
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] > sm / n)
        {
            giv.emplace_back(i, cnt[i]);
        }
        else if (cnt[i] < sm / n)
        {
            tak.emplace_back(i, cnt[i]);
        }
    }
    std::vector<int> ind(m, 0), nxt(m + 1), prv(m + 1);
    std::vector<std::tuple<int, int, int>> ans;
    std::iota(nxt.begin(), nxt.end(), 1);
    std::iota(prv.begin() + 1, prv.end(), 0);
    int s = 0;
    for (auto &&[v, c] : giv)
    {
        while (s < m && ind[s] >= (int)tak.size())
        {
            s++;
        }
        // for (int j = s; j < m; j++)
        for (int j = s; j < m; j = nxt[j])
        {
            // std::cout << j << ' ';
            if (j != s && ind[j] >= (int)tak.size())
            {
                nxt[prv[j]] = nxt[j];
                prv[nxt[j]] = prv[j];
                continue;
            }
            if (c == sm / n)
            {
                break;
            }
            // std::cout << j << ' ';
            assert(c > sm / n);
            if (inp[v][j] == 0)
            {
                continue;
            }
            // std::cout << j << ' ';
            for (int k = ind[j]; k < (int)tak.size(); k++)
            {
                // std::cout << k << '-';
                auto &&[i, c_2] = tak[k];
                assert(c_2 < sm / n);
                if (inp[i][j] == 0)
                {

                    ans.emplace_back(v, i, j);
                    std::swap(inp[v][j], inp[i][j]);
                    c--;
                    c_2++;
                    if (c_2 == sm / n)
                    {
                        std::swap(tak[k], tak.back());
                        tak.pop_back();
                    }
                    break;
                }
            }
        }
        // std::cout << '\n';
    }
    // for (auto &&[i, c] : giv)
    // {
    //     assert(c == sm / n);
    // }
    // for (auto &&[i, c] : tak)
    // {
    //     assert(c == sm / n);
    // }
    // for (auto &&i : inp)
    // {
    //     assert(std::count(i.begin(), i.end(), 1) == sm / n);
    // }
    printf("%d\n", (int)ans.size());
    for (auto &&[i, j, k] : ans)
    {
        printf("%d %d %d\n", i + 1, j + 1, k + 1);
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