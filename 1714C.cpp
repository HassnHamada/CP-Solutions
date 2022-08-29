#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 24 * 60, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

// int arr[N], vis[N], vid;

void run()
{
    int n;
    scanf("%d", &n);
    string ans;
    while (n)
    {
        int v = min(n, 9 - (int)ans.size());
        ans.push_back(v + '0');
        n -= v;
    }
    reverse(ans.begin(), ans.end());
    printf("%s\n", ans.c_str());
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
