#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int n, arr[N];
bool hv[N];

bool ok(int i)
{
    return (i > 0 && i < n - 1 && arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) || (i > 0 && i < n - 1 && arr[i] < arr[i - 1] && arr[i] < arr[i + 1]);
}

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        hv[i] = ok(i);
        tot += hv[i];
    }
    int ans = tot;
    for (int i = 1; i < n - 1; i++)
    {
        int t = arr[i];
        arr[i] = arr[i - 1];
        ans = min(ans, tot - hv[i - 1] - hv[i] - hv[i + 1] + ok(i - 1) + ok(i) + ok(i + 1));
        arr[i] = arr[i + 1];
        ans = min(ans, tot - hv[i - 1] - hv[i] - hv[i + 1] + ok(i - 1) + ok(i) + ok(i + 1));
        arr[i] = t;
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
    // while (scanf("%d"/, &n), n)
    {
        run();
    }

    return 0;
}
