#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int aaa[N], bbb[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", aaa + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", bbb + i);
    }
    for (int i = 0, j = 0; i < n; i++)
    {
        while (bbb[j] < aaa[i])
        {
            j += 1;
        }
        printf("%d%c", bbb[j] - aaa[i], " \n"[i + 1 == n]);
    }
    for (int i = 0, j = 0; i < n; i++)
    {
        j = max(i, j);
        while (j + 1 < n && aaa[j + 1] <= bbb[j])
        {
            j += 1;
        }
        printf("%d%c", bbb[j] - aaa[i], " \n"[i + 1 == n]);
    }
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