#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

// char str[M], ans[N];
char str[N];
multimap<string, int> sss;

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        sss.emplace(str, i);
    }
    for (auto &&i : sss)
    {
        bool ok = false;
        int m = i.first.size();
        for (int j = 1; j < m; j++)
        {
            string a = i.first.substr(0, j), b = i.first.substr(j, m - j);
            if (sss.find(a) == sss.end() || sss.find(b) == sss.end())
            {
                continue;
            }
            ok = true;
            break;
        }
        str[i.second] = "01"[ok];
    }
    str[n] = '\0';
    printf("%s\n", str);
    sss.clear();
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