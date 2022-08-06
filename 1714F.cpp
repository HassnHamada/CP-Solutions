#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

// struct Node
// {
//     ll i, a, b;
//     Node(ll ni, ll na, ll nb)
//     {
//         this->i = ni;
//         this->a = na;
//         this->b = nb;
//     }
// };
// vector<Node> arr[N];

int ans[N];

void dfs(int m, int a, int b, int c, int n)
{
    if (n == 3)
    {
        return;
    }
    if (a == 1)
    {
        printf("%d %d\n", m, 1);
        dfs(1, a - 1, b - 1, c - 1, n);
    }
    else if (b == 1)
    {
        printf("%d %d\n", m, 2);
        dfs(2, a - 1, b - 1, c - 1, n);
    }
    else if (c == 1)
    {
        printf("%d %d\n", m, 3);
        dfs(3, a - 1, b - 1, c - 1, n);
    }
    else
    {
        printf("%d %d\n", m, n);
        dfs(n, a - 1, b - 1, c - 1, n - 1);
    }
}

void run()
{
    int n, d12, d23, d31;
    scanf("%d%d%d%d", &n, &d12, &d23, &d31);
    int mx = max({d12, d23, d31});
    // vector<int> srt = {d12, d23, d31};
    // sort(srt.begin(), srt.end());
    if (srt[0] + srt[1] != srt[2])
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    if (mx == d12)
    {
        dfs(2, d12, 0, d23, n);
    }
    if (mx == d23)
    {
        dfs(2, d12, 0, d23, n);
    }
    if (mx == d31)
    {
        dfs(3, d31, d23, 0, n);
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
