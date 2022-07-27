#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int n;
char sss[N], ttt[N];

void run()
{
    scanf("%d%s%s", &n, sss, ttt);
    // printf("%s\t\t%s\n", sss, ttt);
    bool ok = count(sss, sss + n, 'a') == count(ttt, ttt + n, 'a') &&
              count(sss, sss + n, 'b') == count(ttt, ttt + n, 'b') &&
              count(sss, sss + n, 'c') == count(ttt, ttt + n, 'c');
    vector<int> bbb;
    for (int i = n - 1; ~i; i--)
    {
        if (sss[i] == 'b')
        {
            bbb.push_back(i);
        }
    }
    for (int i = 0; ok && i < n; i++)
    {
        if (ttt[i] == 'b')
        {
            int j = bbb.back();
            if (j < i)
            {
                while (j < i && sss[j + 1] != 'a')
                {
                    j += 1;
                }
            }
            else if (j > i)
            {
                while (j > i && sss[j - 1] != 'c')
                {
                    j -= 1;
                }
            }
            if (j != i)
            {
                ok = false;
            }
            else
            {
                bbb.pop_back();
            }
        }
    }
    if (ok)
    {
        int s = 0, t = 0;
        for (int i = 0; i < n; i++)
        {
            if (sss[i] != 'b')
            {
                sss[s++] = sss[i];
            }
            if (ttt[i] != 'b')
            {
                ttt[t++] = ttt[i];
            }
        }
        assert(s == t);
        for (int i = 0; ok && i < s; i++)
        {
            ok = sss[i] == ttt[i];
        }
    }
    assert(!ok || bbb.empty());
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
