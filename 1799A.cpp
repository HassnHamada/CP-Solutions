#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    // cout << n << " " << m << endl;
    memset(ans, -1, sizeof(ans[0]) * n);
    set<int> nums;
    for (int i = 0, j = n, v; i < m; i++)
    {
        scanf("%d", &v);
        if (j && nums.find(v) == nums.end())
        {
            ans[--j] = i + 1;
            nums.insert(v);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
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