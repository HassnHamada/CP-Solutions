#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

void run()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf(abs(a - c) < abs(b - c) ? "Tetka\n" : "Kashtanka\n");
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