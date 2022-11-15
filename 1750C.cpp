#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char aaa[N], bbb[N];
int ans[N];

void run()
{
    int n;
    scanf("%d%s%s", &n, aaa, bbb);
    bool ok = strcmp(aaa, bbb) == 0;
    if (!ok)
    {
        ok = true;
        for (int i = 0; ok && i < n; i++)
        {
            ok = aaa[i] != bbb[i];
        }
    }
    printf(ok ? "YES\n" : "NO\n");
    if (ok)
    {
        if (strcmp(aaa, bbb) != 0)
        {
            ans[n - 1] ^= 1;
            for (int i = 0; i < n; i++)
            {
                aaa[i] = aaa[i] == '0' ? '1' : '0';
            }
        }
        assert(strcmp(aaa, bbb) == 0);
        for (int i = 1; i < n; i++)
        {
            if (aaa[i] == '1')
            {
                ans[i] ^= 1;
                ans[i - 1] ^= 1;
            }
        }
        vector<tuple<int, int>> vec;
        if (aaa[0] == '1')
        {
            vec.emplace_back(2, n);
            ans[n - 1] ^= 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (ans[i])
            {
                vec.emplace_back(1, i + 1);
                ans[i] ^= 1;
            }
        }
        printf("%d\n", (int)vec.size());
        for (auto &&[a, b] : vec)
        {
            printf("%d %d\n", a, b);
        }
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