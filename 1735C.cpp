#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 26, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char inp[N], ans[N], str[M];
bool usd[M];
map<char, char> mmm, immm;

bool ok(char c1, char c2, int d = 0)
{
    // cout << c1 << " " << c2 << endl;
    // assert(mmm.find(c1) == mmm.end());
    if (c1 == c2)
    {
        return d == M - 1;
    }
    if (immm.find(c2) == immm.end())
    {
        return true;
    }
    return ok(c1, immm[c2], d + 1);
    // return immm.find(c2) == immm.end() || ok(c1, immm[c2]);
}

bool solve(int ii, int sz)
{
    if (ii == sz)
    {
        return true;
    }
    for (int i = 0; i < M; i++)
    {
        if (i + 'a' != str[ii] && !usd[i] && ok(i + 'a', str[ii]))
        {
            usd[i] = true;
            mmm.insert({str[ii], i + 'a'});
            immm.insert({i + 'a', str[ii]});
            if (solve(ii + 1, sz))
            {
                return true;
            }
            usd[i] = false;
            mmm.erase(str[ii]);
            immm.erase(i + 'a');
        }
    }
    return false;
}

void run()
{
    int n, m = 0;
    scanf("%d", &n);
    scanf("%s", inp);
    mmm.clear();
    immm.clear();
    memset(usd, false, sizeof(usd));
    for (int i = 0; i < n; i++)
    {
        if (!usd[inp[i] - 'a'])
        {
            str[m++] = inp[i];
            usd[inp[i] - 'a'] = true;
        }
    }
    memset(usd, false, sizeof(usd));
    assert(solve(0, m));
    for (int i = 0; i < n; i++)
    {
        assert(mmm.find(inp[i]) != mmm.end());
        ans[i] = mmm[inp[i]];
    }
    ans[n] = '\0';
    printf("%s\n", ans);
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
