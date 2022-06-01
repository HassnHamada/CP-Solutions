#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 5, MOD = 1e9 + 7, HV = 151;
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
        if (bbb[i] < aaa[i])
        {
            swap(aaa[i], bbb[i]);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += abs(aaa[i] - aaa[i + 1]);
        ans += abs(bbb[i] - bbb[i + 1]);
    }
    printf("%lld\n", ans);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}