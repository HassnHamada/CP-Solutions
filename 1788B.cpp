#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 1e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char buf[M];

void run()
{
    int a = 0, b = 0, n = 0;
    scanf("%s", buf);
    for (int i = 0, p = 0; buf[i]; i++)
    {
        int v = buf[i] - '0';
        n = n * 10 + v;
        if (v & 1)
        {
            if (p)
            {
                swap(a, b);
            }
            v >>= 1;
            a = a * 10 + v + 1;
            b = b * 10 + v;
            p ^= 1;
        }
        else
        {
            v >>= 1;
            a = a * 10 + v;
            b = b * 10 + v;
        }
    }
    assert(a + b == n);
    printf("%d %d\n", a, b);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}