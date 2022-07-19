#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 31, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];

void run()
{
    scanf("%s", str);
    int n = strlen(str), ans = 0;
    for (int i = 0; i < n; ans++)
    {
        set<char> sss;
        while (i < n)
        {
            if (sss.size() == 3 && sss.find(str[i]) == sss.end())
            {
                break;
            }
            sss.insert(str[i++]);
        }
    }
    printf("%d\n", ans);
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
