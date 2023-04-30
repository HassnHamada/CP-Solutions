#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], lg[N];

// 0 -> 0
// 1 -> 1
// 2 -> 2
// 3 -> 2
// 4 -> 3
// 5 -> 3
// .
// .
// 8 -> 4
// .
// .
// 15 -> 4
// 16 -> 5
int ilog2(int n)
{
    int ret = 0;
    while (n)
    {
        n /= 2;
        ret++;
    }
    return ret;
}

void run()
{
    int n, mx = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        lg[i] = ilog2(arr[i]);
        mx = max(mx, lg[i]);
    }
    while (all_of(lg, lg + n, [&mx](int i)
                  { return i == mx; }))
    {
        mx = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i] &= (~(1 << (lg[i] - 1)));
            lg[i] = ilog2(arr[i]);
            mx = max(mx, lg[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n;)
    {
        if (lg[i] == mx)
        {
            for (int j = i - 1, nums[] = {-INF, -INF, arr[i]}; j >= 0 && lg[j] != mx; j--)
            {
                nums[0] = arr[j];
                sort(nums, nums + 3);
                ans = max(ans, nums[1] ^ nums[2]);
            }
            for (int nums[] = {-INF, -INF, arr[i++]}; i < n && lg[i] != mx; i++)
            {
                nums[0] = arr[i];
                sort(nums, nums + 3);
                ans = max(ans, nums[1] ^ nums[2]);
            }
        }
        else
        {
            i++;
        }
    }
    printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}