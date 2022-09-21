#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int t1 = a - 1, t2 = abs(c - b) + c - 1;
    if (t1 == t2)
    {
        printf("3\n");
    }
    else
    {
        printf(t1 < t2 ? "1\n" : "2\n");
    }
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