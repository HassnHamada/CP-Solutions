#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e1 + 10, M = 10, L = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];

void run()
{
    int n;
    scanf("%d\n%s", &n, str);
    sort(str, str + n);
    int m = unique(str, str + n) - str;
    printf("%d\n", n + m);
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
