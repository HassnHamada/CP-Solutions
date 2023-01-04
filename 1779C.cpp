#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int arr[N];

int back(int n, int m)
{
    multiset<int, greater<int>> nums;
    int ret = 0;
    ll tot = 0;
    for (int i = m - 1; i > 0; i--)
    {
        tot += arr[i];
        nums.insert(arr[i]);
        if (tot > 0)
        {
            ret += 1;
            tot -= (*nums.begin()) * 2;
            assert(*nums.begin() > 0);
            nums.erase(nums.begin());
        }
        assert(tot <= 0);
    }
    return ret;
}

int front(int n, int m)
{
    multiset<int> nums;
    int ret = 0;
    ll tot = 0;
    for (int i = m; i < n; i++)
    {
        tot += arr[i];
        nums.insert(arr[i]);
        if (tot < 0)
        {
            ret += 1;
            tot -= (*nums.begin()) * 2;
            assert(*nums.begin() < 0);
            nums.erase(nums.begin());
        }
        assert(tot >= 0);
    }
    return ret;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int ans = back(n, m) + front(n, m);
    printf("%d\n", ans);
    // printf("%d %d\n", back(n, m), front(n, m));
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}