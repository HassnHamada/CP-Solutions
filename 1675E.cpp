#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 26, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

map<char, char> c2c;
char str[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", str);
    c2c.clear();
    char t = 'a';
    for (int i = 0; i < n; i++)
    {
        if (c2c.find(str[i]) == c2c.end())
        {
            c2c.emplace(str[i], str[i]);
            for (auto &&j : c2c)
            {
                if (j.first > str[i])
                {
                    c2c[str[i]] = min(c2c[str[i]], j.second);
                }
            }
            if (c2c[str[i]] > t)
            {
                int v = c2c[str[i]] - t;
                if (v > k)
                {
                    c2c[str[i]] -= k;
                    k = 0;
                }
                else
                {
                    c2c[str[i]] = 'a';
                    k -= v;
                    t = max(t, str[i]);
                }
            }
            else
            {
                c2c[str[i]] = 'a';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        str[i] = c2c[str[i]];
    }
    printf("%s\n", str);
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
