#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    multiset<int> sss;
    ll tot = 0;
    for (int i = 0, v; i < n; i++)
    {
        assert(tot >= 0);
        scanf("%d", &v);
        if (tot + v >= 0)
        {
            sss.insert(v);
            tot += v;
        }
        else if (sss.size() && v > *sss.begin())
        {
            tot += v - *sss.begin();
            sss.erase(sss.begin());
            sss.insert(v);
        }
    }
    printf("%d\n", (int)sss.size());
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}