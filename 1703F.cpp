#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 64, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    priority_queue<pair<int, int>> pq;
    ll ans = 0, inc = 0;
    for (int i = n - 1; ~i; i--)
    {

        if (arr[i] < i + 1)
        {
            while (!pq.empty() && pq.top().first > i + 1)
            {
                pq.pop();
                inc += 1;
            }
            pq.push({arr[i], i});
            ans += inc;
            // cout << i + 1 << " " << arr[i] << " " << inc << endl;
        }
    }
    printf("%lld\n", ans);
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