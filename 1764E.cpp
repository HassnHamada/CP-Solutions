#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 128, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

pair<int, int> arr[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &arr[i].first, &arr[i].second);
    }
    if (arr[0].first + arr[0].second < k)
    {
        printf("NO\n");
    }
    else
    {
        if (arr[0].first < k)
        {
            int c = 0, t = k - arr[0].second;
            assert(t <= arr[0].first);
            for (int i = 2; i < n; i++)
            {
                c = max(arr[i].first, c + arr[i].second);
            }
        }
        else
        {
            printf("YES\n");
        }
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}