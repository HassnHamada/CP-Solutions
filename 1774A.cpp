#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char inp[N];

void run()
{
    int n;
    scanf("%d%s", &n, inp);
    for (int i = 1, j = inp[0] == '0'; i < n; i++)
    {
        if (inp[i] == '1')
        {
            printf("%c", "+-"[j ^= 1]);
        }
        else
        {
            printf("+");
        }
    }
    printf("\n");
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