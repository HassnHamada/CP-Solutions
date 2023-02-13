#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3 + 10, M = 1e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

// int arr[N];

void run()
{
    int x, y;
    scanf("%d%d", &x, &y);
    // (m + 1)
    // n / (m + 1) * a * m
    // n / (m + 1) * b * (m + 1)
    vector<int> ans;
    for (int i = y + 1; i <= x; i++)
    {
        ans.push_back(i);
    }
    for (int i = x - 1; i >= y; i--)
    {
        ans.push_back(i);
    }
    printf("%d\n", (int)ans.size());
    for (auto &&i : ans)
    {
        printf("%d%c", i, " \n"[i == y]);
    }
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