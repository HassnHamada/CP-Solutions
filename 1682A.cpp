#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 20, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
char str[N];

void run()
{
    int n;
    scanf("%d%s", &n, str);
    int i = n / 2, j = i, k = i;
    while (i >= 0 && str[i] == str[k])
    {
        i--;
    }
    while (j < n && str[j] == str[k])
    {
        j++;
    }
    printf("%d\n", j - i - 1);
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