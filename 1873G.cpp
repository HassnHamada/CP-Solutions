#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
#include <algorithm>
#include <string>
#include <assert.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
char str[N];

void run()
{
    scanf("%s", str);
    int n = strlen(str);
    int a = count(str, str + n, 'A'),
        b = count(str, str + n, 'B');
    int ans = 0;
    if (a && b)
    {
        bool ok = str[0] == 'B' || str[n - 1] == 'B';
        for (int i = 1; !ok && i < n; i++)
        {
            ok = str[i] == 'B' && str[i - 1] == 'B';
        }
        if (!ok)
        {
            int mn = a;
            for (int i = 0; i < n;)
            {
                if (str[i] == 'B')
                {
                    i += 1;
                    continue;
                }
                int v = 0;
                while (str[i] == 'A')
                {
                    i += 1;
                    v += 1;
                }
                mn = min(mn, v);
            }

            ans = a - mn;
        }
        else
        {
            ans = a;
        }
    }
    printf("%d\n", ans);
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