#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 6, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char str[N], bad[M] = {'a', 'e', 'i', 'o', 'u', 'y'};

bool ok(int i)
{
    int a = find(bad, bad + M, str[i]) - bad == M,
        b = find(bad, bad + M, str[i + 1]) - bad == M,
        c = find(bad, bad + M, str[i + 2]) - bad == M;
    return a + b + c > 0 && a + b + c < 3;
}

void run()
{
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n - 2; i++)
    {
        if (!ok(i))
        {
            printf("BAD\n");
            return;
        }
    }
    printf("GOOD\n");
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}