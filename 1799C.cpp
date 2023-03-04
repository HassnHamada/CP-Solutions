#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N], ans[N];
map<char, int> mmm;

void run()
{
    scanf("%s", str);
    // printf("Running %s\n", str);
    int n = strlen(str);
    ans[n] = '\0';
    for (int i = 0; i < n; i++)
    {
        mmm[str[i]]++;
    }
    int sz = 0;
    while (!mmm.empty())
    {
        if (mmm.begin()->second == 1)
        {
            break;
        }
        else
        {
            ans[sz] = mmm.begin()->first;
            ans[n - (++sz)] = mmm.begin()->first;
            mmm.begin()->second -= 2;
            if (mmm.begin()->second == 0)
            {
                mmm.erase(mmm.begin());
            }
        }
    }
    if (!mmm.empty())
    {
        assert(mmm.begin()->second == 1);
        if ((int)mmm.size() == 1)
        {
            // cout << "in 1\n";
            assert(n & 1);
            assert(n - sz * 2 == 1);
            // assert(mmm.size() == 1);
            assert(mmm.begin()->second == 1);
            ans[sz] = mmm.begin()->first;
            // mmm.begin()->second -= 1;
            mmm.erase(mmm.begin());
        }
        // else if (n - sz * 2 == 3 && (int)mmm.size() == 2)
        else if ((int)mmm.size() == 2)
        {
            // assert(mmm.begin()->second == 1);
            // cout << "in 2\n";
            // assert(n & 1);
            // assert(mmm.upper_bound(mmm.begin()->first)->second == 2);
            auto it = mmm.upper_bound(mmm.begin()->first);
            while (it->second)
            {
                assert(it->second > 0);
                if (it->second == 1)
                {
                    break;
                }
                else
                {
                    ans[sz] = it->first;
                    ans[n - (++sz)] = it->first;
                    it->second -= 2;
                }
            }
            if (it->second == 1)
            {
                ans[sz++] = it->first;
            }
            mmm.erase(it);
            ans[sz] = mmm.begin()->first;
            mmm.erase(mmm.begin());
        }
        else
        {
            // cout << "in 3\n";
            assert(mmm.size() >= 3);
            ans[n - sz - 1] = mmm.begin()->first;
            mmm.erase(mmm.begin());
            ans[sz++] = mmm.begin()->first;
            if (--mmm.begin()->second == 0)
            {
                mmm.erase(mmm.begin());
            }
            for (int i = sz; i <= n - sz - 1; i++)
            {
                assert(!mmm.empty());
                assert(mmm.begin()->second > 0);
                ans[i] = mmm.begin()->first;
                if (--mmm.begin()->second == 0)
                {
                    mmm.erase(mmm.begin());
                }
            }
        }
        // while (!mmm.empty() && mmm.begin()->second == 0)
        // {
        //     mmm.erase(mmm.begin());
        // }
    }
    assert(mmm.empty());
    printf("%s\n", ans);
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

