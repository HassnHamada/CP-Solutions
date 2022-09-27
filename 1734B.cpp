#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e2 + 10, M = 1e9, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;


void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d%c", j == 0 || j == i, " \n"[j == i]);
        }
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