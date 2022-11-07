#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (n + 1) / 2);
    int l = 1, h = n;
    while (l <= h)
    {
        printf("%d %d\n", (l - 1) * 3 + 1, h * 3);
        l++;
        h--;
    }
    // if (l == h)
    // {
    //     printf("%d %d\n", (l - 1) * 3 + 1, h * 3);
    // }
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