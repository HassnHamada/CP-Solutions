#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 450, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int aaa[N], bbb[N], ans[N], srt[N << 1], xxx[N << 1], yyy[N << 1], dif[N << 1];

struct Q
{
    int x, y, i;
    bool operator<(Q &other)
    {
        if (x / M == other.x / M)
        {
            return y < other.y;
        }
        return x / M == other.x / M;
    }
} qqq[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", aaa + i);
        srt[i] = aaa[i];
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", bbb + i);
        srt[n + i] = bbb[i];
    }
    sort(srt, srt + 2 * n);
    int m = unique(srt, srt + 2 * n) - srt;
    for (int i = 0; i < n; i++)
    {
        aaa[i] = lower_bound(srt, srt + m, aaa[i]) - srt;
        bbb[i] = lower_bound(srt, srt + m, bbb[i]) - srt;
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &qqq[i].x, &qqq[i].y);
        qqq[i].i = i;
    }
    sort(qqq, qqq + q);
    // for (int i = 0; i < q; i++)
    // {
    //     cout << qqq[i].x << " " << qqq[i].y << endl;
    // }

    int xx = 0, yy = 0, zz = 0;
    // unordered_map<int, int> xxx, yyy;
    // unordered_set<int> dif;
    for (int i = 0; i < q; i++)
    {
        int x = qqq[i].x, y = qqq[i].y;
        while (xx < x)
        {
            if (!xxx[aaa[xx]]++)
            {
                dif[aaa[xx]] ^= 1;
                // if (dif[aaa[xx]])
                // {
                //     dif.erase(aaa[xx]);
                // }
                // else
                // {
                //     dif.insert(aaa[xx]);
                // }
                zz += dif[aaa[xx]] ? 1 : -1;
            }
            xx++;
        }
        while (yy < y)
        {
            if (!yyy[bbb[yy]]++)
            {
                dif[bbb[yy]] ^= 1;
                zz += dif[bbb[yy]] ? 1 : -1;
                // if (dif.count(bbb[yy]))
                // {
                //     dif.erase(bbb[yy]);
                // }
                // else
                // {
                //     dif.insert(bbb[yy]);
                // }
            }
            yy++;
        }
        while (xx > x)
        {
            if (!--xxx[aaa[--xx]])
            {
                dif[aaa[xx]] ^= 1;
                zz += dif[aaa[xx]] ? 1 : -1;
                // if (dif.count(aaa[xx]))
                // {
                //     dif.erase(aaa[xx]);
                // }
                // else
                // {
                //     dif.insert(aaa[xx]);
                // }
            }
        }
        while (yy > y)
        {
            if (!--yyy[bbb[--yy]])
            {
                dif[bbb[yy]] ^= 1;
                zz += dif[bbb[yy]] ? 1 : -1;
                // if (dif.count(bbb[yy]))
                // {
                //     dif.erase(bbb[yy]);
                // }
                // else
                // {
                //     dif.insert(bbb[yy]);
                // }
            }
        }
        ans[qqq[i].i] = zz;
    }
    for (int i = 0; i < q; i++)
    {
        printf(ans[i] ? "No\n" : "Yes\n");
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