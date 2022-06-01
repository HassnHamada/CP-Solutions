#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
// int aaa[N], bbb[N], ccc[N];

void run()
{
    int n;
    scanf("%d", &n);
    set<int> sss;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        sss.insert(v);
    }
    for (int i = 0; i < N; i++)
    {
        if (!sss.count(i))
        {
            printf("%d\n", i);
            break;
        }
    }
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