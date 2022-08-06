#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + m);
    priority_queue<int> pq;
    for (int i = 1; i < m; i++)
    {
        pq.push(arr[i] - arr[i - 1] - 1);
    }
    pq.push(n - arr[m - 1] + arr[0] - 1);
    int ii = 0, ans = 0;
    while (!pq.empty())
    {
        int t = pq.top();
        pq.pop();
        t -= ii * 2;
        if (t <= 0)
        {
            continue;
        }
        if (t == 1)
        {
            ans += t;
            ii += 1;
        }
        else
        {
            ans += t - 1;
            ii += 2;
        }
    }
    printf("%d\n", n - ans);
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
