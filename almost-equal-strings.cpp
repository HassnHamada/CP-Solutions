#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 20, M = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int my_pow[N], n;
char str[N];

struct HASH
{
    int v, b, m, s;
    void extend(HASH &other)
    {
        assert(this->m == other.m && this->b == other.b);
        v = (1ll * v * my_pow[other.s] + other.v) % m;
        s += other.s;
    }
} seg[N << 1], EMP{0, HV, MOD, 0};

void build(int i = 0, int s = 0, int e = n - 1)
{
    if (s == e)
    {
        seg[i] = {str[s], HV, MOD, 1};
    }
    else
    {
        int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
        build(l, s, m);
        build(r, m + 1, e);
        seg[i] = seg[l];
        seg[i].extend(seg[r]);
    }
}

HASH get(int qs, int qe, int i = 0, int s = 0, int e = n - 1)
{
    if (qs > e || qe < s)
    {
        return EMP;
    }
    if (s >= qs && e <= qe)
    {
        return seg[i];
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    HASH ret = get(qs, qe, l, s, m),
         tem = get(qs, qe, r, m + 1, e);
    ret.extend(tem);
    return ret;
}
bool match(int i, int j, int k, int l)
{
    if (j - i != l - k)
    {
        return false;
    }
    if (j - i == 0)
    {
        return true;
    }
    auto h1 = get(i, j);
    auto h2 = get(k, l);
    if (h1.v == h2.v)
    {
        return true;
    }
    int m = (j - i) / 2;
    auto h3 = get(i, i + m);
    auto h4 = get(k, k + m);
    auto h5 = get(i + m + 1, j);
    auto h6 = get(k + m + 1, l);
    if (h3.v == h4.v || h5.v == h6.v)
    {
        if (h3.v == h4.v)
        {
            return match(i + m + 1, j, k + m + 1, l);
        }
        return match(i, i + m, k, k + m);
    }
    return false;
}

void run()
{
    my_pow[0] = 1;
    for (int i = 1; i < N; i++)
    {
        my_pow[i] = 1ll * my_pow[i - 1] * HV % MOD;
    }
    scanf("%d%s", &n, str);
    build();
    // for (int i = 0; i < n; i++)
    // {
    //     cout << get(i, i).v << endl;
    // }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int i, j, k, l;
        scanf("%d%d%d%d", &i, &j, &k, &l);
        printf(match(i - 1, j - 1, k - 1, l - 1) ? "SIMILAR\n" : "DIFFERENT\n");
    }

    // printf("%d %s", n, str);
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
