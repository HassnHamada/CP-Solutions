#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e4 + 10, M = 5e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
pair<int, int> aaa[N], bbb[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &aaa[i].first);
        aaa[i].second = 1;
        while (aaa[i].first % m == 0)
        {
            aaa[i].first /= m;
            aaa[i].second *= m;
        }
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &bbb[i].first);
        bbb[i].second = 1;
        while (bbb[i].first % m == 0)
        {
            bbb[i].first /= m;
            bbb[i].second *= m;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << aaa[i].first << " " << aaa[i].second << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < k; i++)
    // {
    //     cout << bbb[i].first << " " << bbb[i].second << endl;
    // }
    // cout << endl;

    int ii = 0, jj = 0;
    while (ii < n && jj < k)
    {
        // cout << ii << " " << jj << endl;
        assert(aaa[ii].second && bbb[jj].second);
        if (aaa[ii].first == bbb[jj].first)
        {
            int mn = min(aaa[ii].second, bbb[jj].second);
            aaa[ii].second -= mn;
            bbb[jj].second -= mn;
            if (aaa[ii].second == 0)
            {
                ii += 1;
            }
            if (bbb[jj].second == 0)
            {
                jj += 1;
            }
        }
        else
        {
            break;
        }
    }
    printf(ii != n || jj != k ? "No\n" : "Yes\n");
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
