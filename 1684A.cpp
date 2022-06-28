#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e2 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char inp[N];

void run()
{
    scanf("%s", inp);
    int n = strlen(inp), mn = '9';
    for (int i = 0; inp[i]; i++)
    {
        mn = min(mn, (int)(inp[i]));
    }
    printf("%c\n", n == 2 ? inp[1] : mn);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d"/, &n), n)
    {
        run();
    }

    return 0;
}
