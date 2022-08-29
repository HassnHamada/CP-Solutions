#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 26, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

// int ind[M];
char str[N];

void run()
{
    scanf("%s", str);
    map<char, int> ind;
    for (int i = 0; str[i]; i++)
    {
        if (ind.find(str[i]) == ind.end())
        {
            ind.emplace(str[i], -1);
        }
    }
    bool ok = true;
    for (int i = 0; str[i]; i++)
    {
        int j = ind[str[i]];
        for (auto &&k : ind)
        {
            if (j > k.second)
            {
                ok = false;
            }
        }
        ind[str[i]] = i;
    }
    printf(ok ? "YES\n" : "NO\n");
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