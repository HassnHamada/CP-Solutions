#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 10, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

char inp[N];

void run()
{
    int n, ans = 0;
    scanf("%d%s", &n, inp);
    for (int i = 0; i < n; i++)
    {
        vector<int> frq(M);
        int cnt = 0, mx = 0, j = 0;
        while (i + j < n && mx <= M)
        {
            cnt += frq[inp[i + j] - '0']++ == 0;
            mx = max(mx, frq[inp[i + j++] - '0']);
            ans += mx <= cnt;
        }
    }
    printf("%d\n", ans);
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
