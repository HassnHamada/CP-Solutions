#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 200, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int pos[N], tim[N];
int n;

double calc(double m)
{
    double ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret = max(ret, tim[i] + abs(pos[i] - m));
    }
    return ret;
}

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", pos + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", tim + i);
    }
    double l = 0, h = 1e8;
    for (int i = 0; i < M; i++)
    {
        double m = (h - l) / 3;
        double v1 = calc(l + m), v2 = calc(h - m);
        if (v1 < v2)
        {
            h -= m;
        }
        else
        {
            l += m;
        }
    }
    printf("%lf\n", l);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}