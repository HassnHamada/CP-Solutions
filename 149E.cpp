#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

const int N = 1 << 20, M = 2, L = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];
int ppp[N];

struct Data
{
    int i, u, v;
    bool operator==(const struct Data &other) const
    {
        return u == other.u && v == other.v;
    }
    bool operator<(const struct Data &other) const
    {
        return u == other.u ? v < other.v : u < other.u;
    }

} srt[N];

// struct SEG
// {
//     int tre[N << 1];
//     int n;
//     void init(int n)
//     {
//         this->n = n;
//     }
//     void add(int q, int v, int i = 0, int s = 0, int e = n)
//     {
//         if (q > e || q < s)
//         {
//             return;
//         }
//         if (s == e)
//         {
//             assert(s == q);
//             _tre[i] += v;
//             if (_tre[i] <= 0)
//             {
//                 tre[i] = 0;
//             }
//             else if (_tre[i] > 0)
//             {
//                 tre[i] = 1;
//             }
//             return;
//         }
//         int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
//         add(q, v, l, s, m);
//         add(q, v, r, m + 1, e);
//         tre[i] = tre[l] + tre[r];
//         _tre[i] = _tre[l] + _tre[r];
//     }
//     int get(int qs, int qe, int i = 0, int s = 0, int e = n)
//     {
//         if (qs > e || qe < s)
//         {
//             return 0;
//         }
//         if (s >= qs && e <= qe)
//         {
//             return tre[i];
//         }
//         int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
//         return get(qs, qe, l, s, m) + get(qs, qe, r, m + 1, e);
//     }
// } seg1, seg2;

void run()
{
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        ppp[i] = str[i];
    }
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < n; j++)
        {
            srt[j] = {j, ppp[j], (j + (1 << i) >= n ? -1 : ppp[j + (1 << i)])};
        }
        stable_sort(srt, srt + n);
        ppp[srt[0].i] = 0;
        for (int j = 1; j < n; j++)
        {
            ppp[srt[j].i] = ppp[srt[j - 1].i] + (srt[j] == srt[j - 1] ? 0 : 1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", str + srt[i].i);
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}