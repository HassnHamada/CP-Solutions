#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e2 + 10, M = 2e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char ans[N][N];
int n, k, r, c;

void dfs(int cr, int cc)
{
    if (cr < 0 || cr >= n || cc < 0 || cc >= n || ans[cr][cc] == 'X')
    {
        return;
    }
    ans[cr][cc] = 'X';
    dfs(cr, cc + k);
    dfs(cr + k, cc);
    dfs(cr, cc - k);
    dfs(cr - k, cc);
}

void run()
{
    scanf("%d%d%d%d", &n, &k, &r, &c);
    for (int i = 0; i < n; i++)
    {
        fill((char *)(ans + i), (char *)(ans + i) + n, '.');
        ans[i][n] = '\0';
    }
    for (int i = 0; i < k; i++)
    {
        dfs((r - 1 + i) % n, (c - 1 + i) % n);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", (char *)(ans + i));
    }
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