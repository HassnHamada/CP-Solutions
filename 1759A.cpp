#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e1 + 10, M = 10, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

char str[N];

void run()
{
    scanf("%s", str);
    string tar = "Yes";
    bool ok = true;
    for (int i = 0; ok && str[i]; i++)
    {
        ok = tar.find(str[i]) != string::npos;
    }
    for (int i = 0, j = tar.find(str[0]); ok && str[i]; i++, (++j) %= 3)
    {
        ok = str[i] == tar[j];
    }
    printf(ok ? "YES\n" : "NO\n");
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
