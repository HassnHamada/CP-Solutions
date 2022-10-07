#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 26, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char ans[N];
map<pair<int, int>, int> mmm;
int chr[M], srt[M];

// int ask(int i, int j)
// {
//     assert(i <= j);
//     if (mmm.find({i, j}) == mmm.end())
//     {
//         if (i == j)
//         {
//             mmm[{i, j}] = 1;
//         }
//         else
//         {
//             printf("? 2 %d %d\n", i, j);
//             fflush(stdout);
//             scanf("%d", &mmm[{i, j}]);
//         }
//     }
//     return mmm[{i, j}];
// }

int ask(int i, int j)
{
    assert(i <= j);
    printf("? 2 %d %d\n", i, j);
    fflush(stdout);
    int v;
    scanf("%d", &v);
    return v;
}

int nxt(int i, int n, int v)
{
    copy(chr, chr + M, srt);
    sort(srt, srt + M);
    assert(lower_bound(srt, srt + M, INF) - srt == v);
    int l = 0, h = v - 1;
    while (l < h)
    {
        int m = (h - l + 1) / 2 + l;
        int u = ask(srt[m], n);
        assert(v - m >= 1);
        assert(u >= v - m);
        if (u == v - m)
        {
            l = m;
        }
        else
        {
            h = m - 1;
        }
    }
    return srt[l];
}

void run()
{
    memset(chr, 0x3f, sizeof(chr));
    int n;
    scanf("%d", &n);
    for (int i = 0, cc = 0; i < n; i++)
    {
        assert(!ans[i]);
        int nc = ask(1, i + 1); // O(n)
        if (nc == cc + 1)
        {
            printf("? 1 %d\n", i + 1); // O(26)
            fflush(stdout);
            scanf("\n%c", ans + i);
            cc++;
        }
        else if (nc == cc)
        {
            ans[i] = ans[nxt(0, i + 1, nc) - 1]; // O(n * log(26))
        }
        else
        {
            assert(false);
        }
        chr[ans[i] - 'a'] = i + 1;
    }
    printf("! %s\n", ans);
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