#include <bits/stdc++.h>
// #include <stdio.h>
// #include <map>
// #include <assert.h>
using namespace std;
typedef long long ll;

const int N = 2e5;
int ans[N];

struct DT
{
    int val, pos;
    bool operator<(const DT &other) const
    {
        if (this->val == other.val)
        {
            return this->pos > other.pos;
        }
        return this->val < other.val;
    }
    bool operator==(const DT &other) const
    {
        return this->val == other.val || other.pos < this->pos;
    }
} arr[N];

map<DT, int> mmm;

void run()
{
    int n, k;
    scanf("%d", &n);
    memset(ans, 0, sizeof(ans[0]) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].val);
        arr[i].pos = i;
    }
    scanf("%d", &k);
    sort(arr, arr + n);
    int m = unique(arr, arr + n) - arr;
    // for (int i = 0; i < m; i++)
    // {
    //     printf("%d %d\n", arr[i].val, arr[i].pos);
    // }
    // printf("---\n");
    for (int i = 0, j = 0; j < m; j++)
    {
        if (k >= arr[j].val)
        {
            ans[arr[j].pos] = k / arr[j].val;
            k %= arr[j].val;
        }
        for (; i < j; i++)
        {
            if (ans[arr[i].pos] && arr[i].val + k >= arr[j].val)
            {
                int v = arr[j].val - arr[i].val;
                assert(v > 0);
                int w = min(k / v, ans[arr[i].pos]);
                assert(w > 0);
                ans[arr[i].pos] -= w;
                ans[arr[j].pos] += w;
                k -= w * v;
                assert(k >= 0);
            }
        }
    }
    for (int i = n - 2; ~i; i--)
    {
        ans[i] += ans[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }
    // printf("---\n\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}