#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str_1[N], str_2[N];

void run()
{
    int n;
    scanf("%d", &n);
    scanf("%s", str_1);
    scanf("%s", str_2);
    map<char, int> frq;
    for (int i = 0; i < n; i++)
    {
        frq[str_1[i]]++;
        frq[str_2[i]]++;
    }
    bool ok = true;
    for (auto &&i : frq)
    {
        if (i.second & 1)
        {
            ok = false;
        }
    }
    if (ok)
    {
        map<char, int> frq_1, frq_2, ans;
        for (int i = 1; i < n; i += 2)
        {
            frq_1[str_1[i]]++;
            frq_2[str_2[i]]++;
        }
        for (int i = 0; i < n; i += 2)
        {
            ans[str_1[i]]++;
            ans[str_2[i]]++;
        }
        for (auto &&i : frq)
        {
            int mx = frq_1[i.first], mn = frq_2[i.first];
            if (mx < mn)
            {
                swap(mx, mn);
            }
            // cout << i.first << " " << mn + ans[i.first] << " " << i.second << endl;
            if (mn + ans[i.first] < i.second / 2)
            {
                ok = false;
            }
        }
    }
    // if (ok)
    // {
    //     ans.clear();
    //     for (int i = 0; i < 2 * n; i += 2)
    //     {
    //         ans[(i / n ? str_1 : str_2)[i % n]]++;
    //     }
    //     for (auto &&i : frq)
    //     {
    //         if (ans[i.first] >= i.second / 2)
    //         {
    //             ok = false;
    //         }
    //     }
    // }
    printf(ok ? "YES\n" : "NO\n");
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}