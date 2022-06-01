#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int frq[N];

void run()
{
    int n;
    scanf("%d", &n);
    memset(frq, 0, sizeof(frq));
    bool b = false;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        b |= frq[v]++;
    }
    if (frq[0])
    {
        cout << n - frq[0] << endl;
    }
    else if (b)
    {
        cout << n << endl;
    }
    else
    {
        cout << n + 1 << endl;
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