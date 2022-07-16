#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 1e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
// char tem[M];
int ans[N];

void run()
{
    int n;
    scanf("%d", &n);
    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d", ans + 1);
    printf("? 1 3\n");
    fflush(stdout);
    scanf("%d", ans + 2);
    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d", ans + 3);
    ans[2] -= ans[1];
    ans[3] -= ans[2];
    swap(ans[2], ans[3]);
    ans[1] -= ans[2];
    for (int i = 4; i <= n; i++)
    {
        printf("? %d %d\n", i - 1, i);
        fflush(stdout);
        scanf("%d", ans + i);
        ans[i] -= ans[i - 1];
    }
    printf("!");
    for (int i = 1; i <= n; i++)
    {
        printf(" %d", ans[i]);
    }
    printf("\n");
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}