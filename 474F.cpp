#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], st_gcd[N][M], lg[N];
pair<int, int> st_min[N][M];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void st(int n)
{
    for (int i = 2; i <= n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i <= lg[n]; i++)
    {
        for (int j = 0; j + (1 << (i - 1)) < n; j++)
        {
            if (st_min[j + (1 << (i - 1))][i - 1].first < st_min[j][i - 1].first)
            {
                st_min[j][i] = st_min[j + (1 << (i - 1))][i - 1];
            }
            else if (st_min[j + (1 << (i - 1))][i - 1].first > st_min[j][i - 1].first)
            {
                st_min[j][i] = st_min[j][i - 1];
            }
            else
            {
                st_min[j][i] = st_min[j + (1 << (i - 1))][i - 1];
                st_min[j][i].second += st_min[j][i - 1].second;
            }
            st_gcd[j][i] = gcd(st_gcd[j][i - 1], st_gcd[j + (1 << (i - 1))][i - 1]);
        }
    }
}

pair<int, int> getmin(int s, int e)
{
    pair<int, int> ret{INF, 0};
    for (int i = M - 1; i >= 0; i--)
    {
        if ((1 << i) <= e - s + 1)
        {
            if (st_min[s][i].first < ret.first)
            {
                ret = st_min[s][i];
            }
            else if (st_min[s][i].first == ret.first)
            {
                ret.second += st_min[s][i].second;
            }
            s += 1 << i;
        }
    }
    return ret;
}

int getgcd(int s, int e)
{
    int i = lg[e - s + 1];
    return gcd(st_gcd[s][i], st_gcd[e - (1 << i) + 1][i]);
}

void run()
{
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        st_gcd[i][0] = st_min[i][0].first = arr[i];
        st_min[i][0].second = 1;
    }
    st(n);
    scanf("%d", &t);
    while (t--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        --l, --r;
        int _gcd = getgcd(l, r);
        pair<int, int> _min = getmin(l, r);
        // fprintf(stderr, "Query (l=%d, r=%d)\n\tGCD: %d\t MIN: %d(%d)\n", l + 1, r + 1, _gcd, _min.first, _min.second);
        printf("%d\n", (r - l + 1) - (_min.first == _gcd) * _min.second);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    freopen("_error.txt", "w", stderr);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}