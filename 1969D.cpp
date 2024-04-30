#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct DT
{
    int a, b;
    bool operator<(const DT other) const
    {
        if (a == other.a)
        {
            return other.b < b;
        }
        return a < other.a;
    }
} arr[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].a);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].b);
    }
    for (int i = 0; i < n; i++)
    {
        while (i < n && arr[i].b < arr[i].a)
        {
            swap(arr[i], arr[--n]);
        }
    }
    sort(arr, arr + n);
    ll p = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; n > k && i < k; i++)
    {
        assert(arr[i].a <= arr[i].b);
        p -= arr[i].a;
        pq.push(arr[i].b);
    }
    for (int i = k; i < n; i++)
    {
        assert(arr[i].a <= arr[i].b);
        p -= arr[i].a;
        pq.push(arr[i].b);
        p += pq.top();
        pq.pop();
        assert((int)pq.size() == k);
        ans = max(ans, p);
    }
    printf("%lld\n", ans);
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