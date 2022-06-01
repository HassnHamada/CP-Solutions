#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 448, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
pair<int, int> aaa[N], bbb[N];
char str[N];
map<pair<int, int>, int> mmm;

int dfs(int i, int j, int o, int z)
{
    // cout << i << " " << j << " " << o << " " << z << endl;
    if (i == j)
    {
        return max(o, z);
    }
    if (mmm.find({i, j}) != mmm.end())
    {
        return mmm[{i, j}];
    }
    int ret = max(o, z);
    if (o < z)
    {
        ret = min(ret, dfs(i + 1, j, o + (str[i] == '1'), z - (str[i] == '0')));
    }
    if (o < z)
    {
        ret = min(ret, dfs(i, j - 1, o + (str[j - 1] == '1'), z - (str[j - 1] == '0')));
    }
    return mmm[{i, j}] = ret;
}

void run()
{
    scanf("%s", str);
    int n = strlen(str),
        z = count(str, str + n, '0');
    for (int i = 0; i < n; i++)
    {
        aaa[i].first = i ? aaa[i - 1].first + (str[i] == '1') : (str[i] == '1');
        aaa[i].second = i ? aaa[i - 1].second - (str[i] == '0') : z - (str[i] == '0');
    }
    bbb[n] = {0, z};
    for (int i = n - 1; ~i; i--)
    {
        bbb[i].first = bbb[i + 1].first + (str[i] == '1');
        bbb[i].second = bbb[i + 1].second - (str[i] == '0');
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << aaa[i].first << " " << aaa[i].second << endl;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << bbb[i].first << " " << bbb[i].second << endl;
    // }
    int ii = 0, jj = n, ans = z;
    while (ii < jj)
    {
        // bool brk = true;
        int a = max(aaa[ii].first + bbb[jj].first, aaa[ii].second - (z - bbb[jj].second));
        int b = max(bbb[jj - 1].first + (ii ? aaa[ii - 1].first : 0), bbb[jj - 1].second - (z - (ii ? aaa[ii - 1].second : z)));
        if (a <= ans && a < b)
        {
            ans = a;
            ii += 1;
            // brk = false;
        }
        else if (b <= ans && b < a)
        {
            ans = b;
            jj -= 1;
            // brk = false;
        }
        else if (a <= ans && b == a)
        {
            // assert(false);
            ans = max(bbb[jj - 1].first + aaa[ii].first, bbb[jj - 1].second - (z - aaa[ii].second));
            ii += 1;
            jj -= 1;
        }
        else
        {
            break;
        }
    }
    // cout << ii << " " << jj << endl;
    printf("%d\n", ans);
    // cout << dfs(0, n, 0, z) << endl;
    // mmm.clear();
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}