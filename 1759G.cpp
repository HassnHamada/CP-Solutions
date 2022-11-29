#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 128, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    set<int, greater<int>> inp, nums;
    for (int i = 1; i < n; i += 2)
    {
        scanf("%d", arr + i);
        inp.insert(arr[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (inp.find(i) == inp.end())
        {
            nums.insert(i);
        }
    }
    bool ok = ((int)inp.size() == (int)nums.size());
    for (int i = n - 1; ok && i > 0; i -= 2)
    {
        auto it = nums.upper_bound(arr[i]);
        if (it == nums.end())
        {
            ok = false;
        }
        else
        {
            arr[i - 1] = *it;
            nums.erase(it);
        }
    }
    if (ok)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", arr[i], " \n"[i + 1 == n]);
        }
    }
    else
    {
        printf("-1\n");
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