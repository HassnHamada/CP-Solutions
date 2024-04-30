#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

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
    int ans = 0;
    for (int i = n - 1, j = n - 1; ~i; i--, j--)
    {
        if (aaa[i] > bbb[j])
        {
            // cerr << i << " " << aaa[i] << " " << j << " " << bbb[j] << endl;
            ans++;
            j++;
        }
    }
    printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    freopen("_error.txt", "w", stderr);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}