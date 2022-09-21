#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int aaa[N], bbb[N], arr[N];
pair<int, int> kkk[N];

void run()
{
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    memset(aaa + 1, 0, sizeof(aaa[0]) * a);
    memset(bbb + 1, 0, sizeof(bbb[0]) * b);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &kkk[i].first);
        aaa[kkk[i].first]++;
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &kkk[i].second);
        bbb[kkk[i].second]++;
    }
    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += k - aaa[kkk[i].first] - bbb[kkk[i].second] + 1;
    }
    assert(ans % 2 == 0);
    printf("%lld\n", ans / 2);
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