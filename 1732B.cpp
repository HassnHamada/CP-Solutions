#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

char inp[N];

void run()
{
    int n;
    scanf("%d", &n);
    scanf("%s", inp);
    n = unique(inp, inp + n) - inp;
    if (inp[0] == '1' || n == 1)
    {
        printf("%d\n", n - 1);
    }
    else
    {
        printf("%d\n", n - 2);
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