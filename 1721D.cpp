#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int aaa[N], bbb[N];
int n;

bool ok(int v)
{
    map<int, int> tem;
    for (int i = 0; i < n; i++)
    {
        tem[(aaa[i] & v)] += 1;
        tem[(bbb[i] & v) ^ v] -= 1;
    }
    return all_of(tem.begin(), tem.end(), [](pair<int, int> i)
                  { return i.second == 0; });
}

int solve(int b, int v)
{
    if (b == -1)
    {
        return v;
    }
    if (ok(v | (1 << b)))
    {
        return solve(b - 1, v | (1 << b));
    }
    return solve(b - 1, v);
}

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", aaa + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", bbb + i);
    }
    printf("%d\n", solve(30, 0));
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