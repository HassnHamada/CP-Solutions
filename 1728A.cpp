#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 2e1 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

pair<int, int> arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    sort(arr, arr + n);
    printf("%d\n", arr[n - 1].second + 1);
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