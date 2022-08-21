#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 10, M = 6, MOD = 1e9 + 9, HV = 151, INF = 0x3f3f3f3f;

char str[N];

void extned()
{
    int n = strlen(str);
    for (int i = n - 1; ~i; i--)
    {
        str[2 * i + 1] = str[i];
        str[2 * i] = i ? '.' : '$';
    }
    str[2 * n] = '\0';
}

void run()
{
    scanf("%s", str);
    extned();
    printf("%s\n", str);
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}