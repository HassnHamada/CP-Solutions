#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 17, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    map<int, ll> ans, div, nxt;
    for (int i = 0; i < n; i++)
    {
        nxt.clear();
        for (auto &&j : div)
        {
            nxt[gcd(j.first, arr[i])] += j.second;
        }
        nxt[arr[i]] += 1;
        swap(div, nxt);
        for (auto &&j : div)
        {
            ans[j.first] += j.second;
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int x;
        scanf("%d", &x);
        printf("%lld\n", ans[x]);
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
