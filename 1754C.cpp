#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void C1(int n)
{
    if (n & 1)
    {
        printf("-1\n");
    }
    else
    {
        vector<tuple<int, int>> ans;
        for (int i = 0; i < n; i += 2)
        {
            if (arr[i] == arr[i + 1])
            {
                ans.emplace_back(i + 1, i + 2);
            }
            else
            {
                ans.emplace_back(i + 1, i + 1);
                ans.emplace_back(i + 2, i + 2);
            }
        }
        printf("%d\n", (int)ans.size());
        for (auto &&[i, j] : ans)
        {
            printf("%d %d\n", i, j);
        }
    }
}

void C2(int n)
{
    int ones = 0;
    for (int i = 0; i < n; i++)
    {
        ones += arr[i] ? 1 : 0;
    }
    if (ones & 1)
    {
        printf("-1\n");
    }
    else
    {
        vector<tuple<int, int>> ans;
        for (int i = 0, j = 0; i < n; i = max(i + 1, j + 1))
        {
            if (arr[i] == 0)
            {
                ans.emplace_back(i + 1, i + 1);
                continue;
            }
            j = i + 1;
            while (arr[j] == 0)
            {
                assert(++j < n);
            }
            assert(arr[i]);
            assert(arr[j]);
            if (arr[i] == arr[j])
            {
                if ((j - i) & 1)
                {
                    ans.emplace_back(i + 1, j + 1);
                }
                else
                {
                    ans.emplace_back(i + 1, i + 1);
                    ans.emplace_back(i + 2, j + 1);
                }
            }
            else
            {
                if ((j - i) & 1)
                {
                    ans.emplace_back(i + 1, i + 1);
                    ans.emplace_back(i + 2, j + 1);
                }
                else
                {
                    ans.emplace_back(i + 1, j + 1);
                }
            }
        }
        printf("%d\n", (int)ans.size());
        for (auto &&[i, j] : ans)
        {
            printf("%d %d\n", i, j);
        }
    }
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    // C1(n);
    C2(n);
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