#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 21, L = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

char buf[M], str[L][M];

void run()
{
    int n, id = 0;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n - 2; i++)
    {
        scanf("%s", buf);
        if ((int)strlen(buf) == n - 1)
        {
            // printf("%s\n", buf);
            strcpy((char *)(str + (id++)), buf);
        }
    }
    assert(id == L - 1);
    strcpy(buf, (char *)(str));
    buf[n - 2] = '\0';
    if (strcmp((char *)(str + 1) + 1, buf) == 0)
    {
        strcpy((char *)(str + 2), (char *)(str + 1));
        str[2][n - 1] = str[0][n - 2];
        str[2][n] = '\0';
    }
    else
    {
        strcpy(buf, (char *)(str + 1));
        buf[n - 2] = '\0';
        assert(strcmp((char *)(str) + 1, buf) == 0);
        strcpy((char *)(str + 2), (char *)(str));
        str[2][n - 1] = str[1][n - 2];
        str[2][n] = '\0';
    }
    // printf("%s\n", (char *)(str + 2));
    bool ok = true;
    for (int i = 0; ok && i < n / 2; i++)
    {
        ok = str[2][i] == str[2][n - i - 1];
    }
    printf(ok ? "YES\n" : "NO\n");
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