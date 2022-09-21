#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e1 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N], ans[N];

void run()
{
    int n, sz = 0;
    scanf("%d%s", &n, str);
    for (int i = n - 1; ~i; i--)
    {
        if (str[i] == '0')
        {
            assert(i >= 2);
            int c = (str[i - 2] - '0') * 10 + str[i - 1] - '0';
            ans[sz++] = c + 'a' - 1;
            i -= 2;
        }
        else
        {
            int c = str[i] - '0';
            ans[sz++] = c + 'a' - 1;
        }
    }
    reverse(ans, ans + sz);
    ans[sz] = '\0';
    printf("%s\n", ans);
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