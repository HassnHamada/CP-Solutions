#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 1e3 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char ans[N][N];
int n, m, a, b;

bool solve()
{
    for (int i = 0; i < n; i++)
    {
        fill((char *)(ans + i), (char *)(ans + i) + m, '0');
        ans[i][m] = '\0';
    }
    for (int i = 0, k = 0, s = 0; i < b; i++, s = 0)
    {
        while (ans[k][s] == '1')
        {
            s += 1;
        }
        for (int j = 0; j < m; j++, k = (k + 1) % n)
        {
            ans[k][(j + s) % m] = '1';
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (count_if((char *)(ans + i), (char *)(ans + i) + m, [](char c)
                     { return c == '1'; }) != a)
        {
            return false;
        }
    }
    return true;
}

void run()
{
    scanf("%d%d%d%d", &n, &m, &a, &b);
    if (solve())
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", (char *)(ans + i));
        }
    }
    else
    {
        printf("NO\n");
        // for (int i = 0; i < n; i++)
        // {
        //     printf("%s\n", (char *)(ans + i));
        // }
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