#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    queue<int> q;
    q.emplace(0);
    for (int i = 1, j = 0; i < n; j = arr[i++])
    {
        if (arr[i] < j)
        {
            j = 0;
            q.pop();
        }
        assert(!q.empty());
        q.push(q.front() + 1);
    }
    int ans = 0;
    while (!q.empty())
    {
        assert(q.front() >= ans);
        ans = q.front();
        q.pop();
    }
    printf("%d\n", ans);
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