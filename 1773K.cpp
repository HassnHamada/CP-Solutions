#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 5e2 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

std::vector<std::pair<int, int>> grf;

void con(int i, int j)
{
    if (i < j)
    {
        grf.emplace_back(i, j);
        con(i + 1, j - 1);
    }
}

bool sure(int n, int k)
{
    std::vector<int> vec(n);
    for (auto &&[i, j] : grf)
    {
        vec[i]++;
        vec[j]++;
    }
    return (int)std::set<int>(vec.begin(), vec.end()).size() == k;
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if (n == 1)
    {
        printf("YES\n0\n");
    }
    else if (n == k)
    {
        printf("NO\n");
    }
    else
    {
        if (n == 2)
        {
            assert(k == 1);
            grf.emplace_back(0, 1);
        }
        else if (k == 1)
        {
            for (int i = 0; i < n; i++)
            {
                grf.emplace_back(i, (i + 1) % n);
            }
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                grf.emplace_back(0, i);
            }
            for (int i = 2; i < k; i++)
            {
                con(1, i);
            }
        }
        assert(!grf.empty());
        assert((int)grf.size() <= n * (n - 1) / 2);
        assert(sure(n, k));
        printf("YES\n%d\n", (int)grf.size());
        for (auto &&[i, j] : grf)
        {
            printf("%d %d\n", i + 1, j + 1);
        }
    }
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