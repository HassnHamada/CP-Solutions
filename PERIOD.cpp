#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 20, M = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char str[N];
int ans[N], my_pow[N];

// ll pow(int b, int p, int m)
// {
//     ll r = 1;
//     while (p)
//     {
//         if (p & 1)
//         {
//             r = r * b % m;
//         }
//         b = 1ll * b * b % m;
//         p >>= 1;
//     }
//     return r;
// }

struct HASH
{
    int v, b, m, s;
    void extend(HASH &other)
    {
        assert(b == other.b && m == other.m);
        // v = (v * pow(b, other.s, m) + other.v) % m;
        v = (1ll * v * my_pow[other.s] + other.v) % m;
        s += other.s;
    }
} seg[N << 1], EMP{0, HV, MOD, 0};

void build(int i, int s, int e)
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

HASH get(int qs, int qe, int i, int s, int e)
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

void run()
{
    int n;
    scanf("%d%s", &n, str);
    memset(ans, 0, sizeof(ans[0]) * (n + 1));
    build(0, 0, n - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << get(i, i, 0, 0, n - 1).v << endl;
    // }

    // vector<int> vec;
    // 1/1 + 1/2 + 1/3
    for (int i = 1; i < n; i++)
    {
        // cout << i << endl;
        // bool ok = true;
        int v = get(0, i - 1, 0, 0, n - 1).v;
        // cout << v << endl;
        if (!ans[i - 1])
        {
            ans[i - 1] = i;
        }
        for (int j = i; j + i - 1 < n; j += i)
        {
            if (v != get(j, j + i - 1, 0, 0, n - 1).v)
            {
                break;
            }
            if (ans[j + i - 1])
            {
                continue;
            }
            ans[j + i - 1] = i;
        }
        // for (int j = 0; j < n; j++)
        // {
        //     cout << ans[j] << " ";
        // }
        // cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (!ans[i] || ans[i] == i + 1)
        {
            continue;
        }
        assert((i + 1) % ans[i] == 0);
        printf("%d %d\n", i + 1, (i + 1) / ans[i]);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    my_pow[0] = 1;
    for (int i = 1; i < N; i++)
    {
        my_pow[i] = 1ll * HV * my_pow[i - 1] % MOD;
    }

    int t = 1;
    scanf("%d", &t);
    // while (t--)
    // // while (scanf("%d", &n), n)
    // {
    //     run();
    // }
    for (int i = 0; i < t; i++)
    {
        printf("Test case #%d\n", i + 1);
        run();
        printf("\n");
    }

    return 0;
}
