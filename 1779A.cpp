#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char inp[N];

void run()
{
    int n;
    scanf("%d%s", &n, inp);
    int l = count(inp, inp + n, 'L'),
        r = count(inp, inp + n, 'R');
    if (l == 0 || r == 0)
    {
        printf("-1\n");
    }
    else if (strstr(inp, "RL"))
    {
        printf("0\n");
    }
    else
    {
        assert(strstr(inp, "LR"));
        printf("%d\n", (int)(strstr(inp, "LR") - inp + 1));
    }
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