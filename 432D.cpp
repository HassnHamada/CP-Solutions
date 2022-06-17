#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char str[N];
int zzz[N];

void computeZ()
{
    int &i = zzz[0];
    int s = 0, e = 0;
    for (i = 1; str[i]; i++)
    {
        if (i >= e)
        {
            s = e = i;
            zzz[i] = 0;
        }
        else
        {
            zzz[i] = zzz[i - s];
        }
        if (i + zzz[i] >= e)
        {
            s = i;
            while (str[e] == str[e - s])
            {
                e++;
            }
            zzz[i] = e - s;
        }
    }
}

void run()
{
    scanf("%s", str);
    int n = strlen(str);
    computeZ();
    map<int, int, greater<int>> mmm;
    for (int i = 0; i < n; i++)
    {
        if (i + zzz[i] != n)
        {
            continue;
        }
        mmm[zzz[i]] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        // cout << zzz[i] << " ";
        auto it = mmm.lower_bound(zzz[i]);
        if (zzz[i] == 0 || it == mmm.end())
        {
            continue;
        }
        it->second++;
        // mmm[zzz[i]]++;
    }
    // cout << endl;
    int v = 0;
    vector<pair<int, int>> vec;
    for (auto &&i : mmm)
    {
        v += i.second;
        vec.push_back({i.first, v});
        // cout << i.first << " " << i.second << endl;
    }
    printf("%d\n", (int)vec.size());
    while (vec.size())
    {
        auto p = vec.back();
        vec.pop_back();
        printf("%d %d\n", p.first, p.second);
    }
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
