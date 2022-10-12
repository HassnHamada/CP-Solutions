#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e2 + 10, M = 3e5, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int aaa[N], bbb[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", aaa + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", bbb + i);
    }
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (aaa[i] ^ bbb[i])
        {
            a += aaa[i];
            b += bbb[i];
        }
    }
    if (a && b)
    {
        if (b > a)
        {
            swap(a, b);
        }
        printf("%d\n", a - b + 1);
    }
    else
    {
        printf("%d\n", a ? a : b);
    }
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