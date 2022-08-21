#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 10, M = 6, MOD = 1e9 + 9, HV = 151, INF = 0x3f3f3f3f;

int ppp[N];
char str[N];

void extend()
{
    int n = strlen(str);
    for (int i = (n + 1) * 2; i; i -= 2)
    {
        str[i] = str[n--];
        str[i - 1] = '#';
    }
    str[0] = '$';
}

void shrink()
{
    int i = 0;
    for (int j = 2; str[j]; j += 2)
    {
        str[i++] = str[j];
    }
    str[i] = '\0';
}

int manacher()
{
    extend();
    int n = strlen(str), c = 1, r = 1;
    memset(ppp, 0, n * sizeof(ppp[0]));
    for (int i = 2; i < n; i++)
    {
        int m = 2 * c - i;
        if (i < r)
        {
            ppp[i] = min(ppp[m], r - i);
        }
        while (str[i + ppp[i] + 1] == str[i - ppp[i] - 1])
        {
            ppp[i]++;
        }
        if (i + ppp[i] > r)
        {
            c = i;
            r = i + ppp[i];
        }
    }
    shrink();
    return max_element(ppp, ppp + n) - ppp;
}

void run()
{
    scanf("%s", str);
    int res = manacher();
    int p = (res - ppp[res] + 1) / 2 - 1;
    str[p + ppp[res]] = '\0';
    printf("%s\n", str + p);
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