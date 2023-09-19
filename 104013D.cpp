#include <bits/stdc++.h>
// #include <map>
// #include <stdio.h>
using namespace std;
typedef long long ll;

const int N = 3e1 + 10;

char buf[N];

map<char, int> inp;

void run()
{
    int n, w, h, s;
    scanf("%d%d%d%d", &n, &w, &h, &s);
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf("\n%c", &c);
        for (int j = 0; j < h; j++)
        {
            scanf("%s", buf);
            int m = unique(buf, buf + w) - buf;
            int cnt = count(buf, buf + m, '#') * 2;
            inp[c] = max(inp[c], cnt);
        }
    }
    char ans = inp.begin()->first;
    for (auto &&[i, j] : inp)
    {
        if (j > inp[ans])
        {
            ans = i;
        }
    }
    for (int i = 0, j = (s + inp[ans] - 1) / inp[ans]; i < j; i++)
    {
        printf("%c", ans);
    }
    printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    run();
    return 0;
}