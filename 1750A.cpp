#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n;
    scanf("%d", &n);
    vector<int> inp(n);
    for (auto &&i : inp)
    {
        scanf("%d", &i);
    }
    printf(inp[0] == 1 ? "Yes\n" : "No\n");
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