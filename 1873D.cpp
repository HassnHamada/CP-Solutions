#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
char str[N];

void run()
{
    int n, k, ans = 0;
    scanf("%d%d%s", &n, &k, str);
    for (int i = 0; i < n;)
    {
        if (str[i] == 'B')
        {
            ans += 1;
            i += k;
        }
        else
        {
            i++;
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