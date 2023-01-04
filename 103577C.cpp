#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e3 + 10, M = 1 << 12, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char str[N];
int pi[N];

int newL(int i, char c, char *ptr)
{
    while (i && ptr[i] != c)
    {
        i = pi[i - 1];
    }
    return i + (int)(ptr[i] == c);
}

void kmp(char *ptr)
{
    for (int i = 1; ptr[i]; i++)
    {
        pi[i] = newL(pi[i - 1], ptr[i], ptr);
    }
}

void run()
{
    while (~scanf("%s", str))
    {
        ll n = strlen(str), ans = 0;
        for (int i = 0; i < n; i++)
        {
            kmp(str + i);
            for (int j = 0; j < n - i; j++)
            {
                ans += pi[j];
            }
        }
        printf("%lld\n", ans);
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}