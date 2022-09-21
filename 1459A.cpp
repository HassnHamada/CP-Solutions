#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 1e3 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char aaa[N], bbb[N];

void run()
{
    int n;
    scanf("%d%s%s", &n, aaa, bbb);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (aaa[i] == bbb[i])
        {
            continue;
        }
        ans += aaa[i] > bbb[i] ? 1 : -1;
    }
    if (ans)
    {
        printf(ans > 0 ? "RED\n" : "BLUE\n");
    }
    else
    {
        printf("EQUAL\n");
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}