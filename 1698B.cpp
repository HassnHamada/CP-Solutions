#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 30, MOD = 1e9 + 7, HV = 151;
int arr[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        ans += (arr[i] > arr[i - 1] + arr[i + 1] ? 1 : 0);
    }
    assert(ans <= (n - 1) / 2);
    printf("%d\n", k == 1 ? (n - 1) / 2 : ans);
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