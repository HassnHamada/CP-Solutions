#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <stdio.h>
#include <string.h>
#include <algorithm>
#endif
using namespace std;
typedef long long ll;

const int N = (int)(4e5 + 10);
int pal[N];
char str[N];

void extend()
{
    int n = (int)strlen(str);
    for (int i = (n + 1) * 2; i;)
    {
        str[i--] = str[n--];
        str[i--] = '#';
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

void manacher()
{
    int n = (int)strlen(str), c = 1, r = 1;
    memset(pal, 0, (unsigned long)(n) * sizeof(pal[0]));
    for (int i = 2; i < n; i++)
    {
        int m = 2 * c - i;
        if (i < r)
        {
            pal[i] = min(pal[m], r - i);
        }
        while (str[i + pal[i] + 1] == str[i - pal[i] - 1])
        {
            pal[i]++;
        }
        if (i + pal[i] > r)
        {
            c = i;
            r = i + pal[i];
        }
    }
}

void run()
{
    int n, q;
    scanf("%d%d%s", &n, &q, str);
    extend();
    manacher();
    while (q--)
    {
        int l, r, ans = 0;
        scanf("%d%d", &l, &r);
        for (int i = 2; i <= r - l + 1; i++)
        {
            for (int j = l * 2 + i - 1; j <= 2 * r - i + 1; j += 2)
            {
                if (pal[j] < i)
                {
                    ans += i;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}