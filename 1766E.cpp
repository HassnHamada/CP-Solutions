#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int arr[N], tem[N];

int calc(int i, int j)
{
    std::vector<int> vec = {arr[i]};
    for (i++; i <= j; i++)
    {
        bool ok = false;
        for (auto &&k : vec)
        {
            if (k & arr[i])
            {
                k = arr[i];
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            vec.push_back(arr[i]);
        }
    }
    return vec.size();
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    // printf(ok(n) ? "YES\n" : "NO\n");
    int ans = 0;
    // int ans = 0, m = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == 0)
    //     {
    //         ans += (i + 1) * (n - i);
    //         for (int j = 0; j < i; j++)
    //         {
    //             ans += calc(j, i - 1);
    //         }
    //     }
    //     else
    //     {
    //         tem[m++] = arr[i];
    //     }
    // }
    // std::cout << ans << std::endl;
    // std::swap(arr, tem);
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = i; j < m; j++)
    //     {
    //         std::cout << i << " " << j << " " << calc(i, j) << std::endl;
    //         ans += calc(i, j);
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            std::cout << i << " " << j << " " << calc(i, j) << std::endl;
            ans += calc(i, j);
        }
    }
    std::cout << ans << std::endl;
}

int main()
{
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}