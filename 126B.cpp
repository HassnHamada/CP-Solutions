#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char str[N];
int fff[N], zzz[N];

int newL(int i, char c)
{
    while (i && str[i] != c)
    {
        i = fff[i - 1];
    }
    return i + (int)(str[i] == c);
}

void computeF()
{
    for (int i = 1; str[i]; i++)
    {
        fff[i] = newL(fff[i - 1], str[i]);
    }
}

void computeZ()
{
    int &i = zzz[0];
    int l = 0, r = 0;
    for (i = 1; str[i]; i++)
    {
        if (i >= r)
        {
            l = r = i;
            zzz[i] = 0;
        }
        else
        {
            zzz[i] = zzz[i - l];
        }
        if (i + zzz[i] >= r)
        {
            l = i;
            while (str[r] == str[r - l])
            {
                r++;
            }
            zzz[i] = r - l;
        }
    }
}

void run()
{
    scanf("%s", str);
    int n = strlen(str);
    // computeF();
    computeZ();
    // for (int i = 0; i < n; i++)
    // {
    //     cout << zzz[i] << " ";
    // }
    // cout << endl;
    set<int, greater<int>> sss;
    // set<int> sss;
    // int mx = 0;
    for (int i = 1; i < n; i++)
    {
        if (i + zzz[i] == n)
        {
            // mx = max(mx, zzz[i]);
            sss.insert(zzz[i]);
        }
    }
    // for (auto &&i : sss)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    int ans = -1;
    for (int i = 1; i < n; i++)
    {
        if (!zzz[i])
        {
            continue;
        }
        int z = zzz[i];
        if (z + i == n)
        {
            z -= 1;
        }
        // ans = max(ans, min(z, *sss.begin()));
        auto it = sss.lower_bound(z);
        if (it != sss.end())
        {
            ans = max(ans, *it);
        }
    }
    if (~ans)
    {
        printf("%s\n", str + n - ans);
    }
    else
    {
        printf("Just a legend\n");
    }
    // set<int, greater<int>> s1, s2;
    // for (int i = 1; i < n; i++)
    // {
    //     if (zzz[i] == 0)
    //     {
    //         continue;
    //     }
    //     (i + zzz[i] == n ? s2 : s1).insert(zzz[i]);
    // }
    // for (auto &&i : s1)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto &&i : s2)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // while (s1.size() && s2.size() && *s1.begin() != *s2.begin())
    // {
    //     if (*s1.begin() < *s2.begin())
    //     {
    //         swap(s1, s2);
    //     }
    //     s1.erase(s1.begin());
    // }
    // for (auto &&i : s1)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto &&i : s2)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // if (s1.size() && s2.size())
    // {
    //     printf("%s\n", str + n - *s1.begin());
    // }
    // else
    // {
    //     printf("Just a legend\n");
    // }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
