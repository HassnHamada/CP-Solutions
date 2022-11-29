#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 128, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int inp[N];

void run()
{
    int n, p;
    scanf("%d%d", &n, &p);
    set<int> nums;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", inp + i);
        nums.insert(inp[i]);
    }
    if ((int)nums.size() == p)
    {
        printf("0\n");
    }
    else
    {
        int v = count_if(nums.begin(), nums.end(), [&n](int i)
                         { return i < inp[n - 1]; });
        if (v == inp[n - 1])
        {
            assert(nums.find(p) == nums.end());
            int ans = p - 1;
            while (nums.find(ans) != nums.end())
            {
                ans--;
            }
            printf("%d\n", ans - inp[n - 1]);
        }
        else
        {
            int c = 1, np = inp[n - 1] - 1, ans = p - inp[n - 1];
            nums.insert(inp[n - 1] = 0);
            for (int i = n - 2; c && i >= 0; i--)
            {
                nums.insert(++inp[i] %= p);
                c = inp[i] == 0;
            }
            if (c)
            {
                nums.insert(1);
            }
            while (nums.find(np) != nums.end())
            {
                np--;
            }
            printf("%d\n", max(np, 0) + ans);
        }
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}