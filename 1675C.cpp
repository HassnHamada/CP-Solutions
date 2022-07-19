#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1 << 11, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];

void run()
{
    scanf("%s", str);
    int n = strlen(str);
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
        {
            l = i;
        }
        if (str[n - i - 1] == '0')
        {
            r = n - i - 1;
        }
        assert(r >= l);
    }
    printf("%d\n", r - l + 1);
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
