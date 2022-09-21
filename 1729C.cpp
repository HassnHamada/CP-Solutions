#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];
pair<char, int> srt[N];
// int ans[N];

void run()
{
    scanf("%s", str);
    int n = strlen(str), l, h;
    char s = str[0], e = str[n - 1];
    if (e < s)
    {
        for (int i = 0; i < n; i++)
        {
            srt[i].first = str[i];
            srt[i].second = -(i + 1);
        }
        sort(srt, srt + n, greater<pair<char, int>>());
        sort(str, str + n, greater<char>());
        l = lower_bound(str, str + n, s, greater<char>()) - str;
        h = upper_bound(str, str + n, e, greater<char>()) - str;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            srt[i].first = str[i];
            srt[i].second = i + 1;
        }
        sort(srt, srt + n);
        sort(str, str + n);
        l = lower_bound(str, str + n, s) - str;
        h = upper_bound(str, str + n, e) - str;
    }
    // printf("%s\n", str);
    printf("%d %d\n", abs(e - s), h - l);
    // cout << l << " " << h << endl;
    assert(abs(srt[l].second) == 1 && abs(srt[h - 1].second) == n);
    for (int i = l; i < h; i++)
    {
        printf("%d%c", abs(srt[i].second), " \n"[i + 1 == h]);
        // ans[i] = srt[i].second;
    }
    // sort(ans + l, ans + h);
    // if (p)
    // {
    //     reverse(ans + l, ans + h);
    // }
    // for (int i = l; i < h; i++)
    // {
    //     printf("%d%c", ans[i], " \n"[i + 1 == h]);
    // }
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