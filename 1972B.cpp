#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];

bool play(char *ptr, bool t, int n)
{
    if (n == 1)
    {
        return ptr[0] == 'U' ? t : !t;
    }
    // fprintf(stderr, "%s\n", ptr);
    char *tmp = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] == 'U')
        {
            move(ptr, ptr + i, tmp);
            move(ptr + i + 1, ptr + n + 1, tmp + i);
            tmp[(i - 1 + n - 1) % (n - 1)] = tmp[(i - 1 + n - 1) % (n - 1)] == 'U' ? 'D' : 'U';
            tmp[i % (n - 1)] = tmp[i % (n - 1)] == 'U' ? 'D' : 'U';
            if (play(tmp, !t, n - 1) == t)
            {
                free(tmp);
                return t;
            }
        }
    }
    free(tmp);
    return !t;
}

void run()
{
    int n;
    scanf("%d%s", &n, str);
    int u = count(str, str + n, 'U');
    printf(u & 1 ? "YES\n" : "NO\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    freopen("_error.txt", "w", stderr);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}