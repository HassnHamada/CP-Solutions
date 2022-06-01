#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    vector<int> vec(40, 0);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        for (int i = 0; (1 << i) <= v; i++)
        {
            vec[i] += ((v >> i) & 1);
        }
    }
    bool k = true;
    for (auto &&i : vec)
    {
        // cout << i << " ";
        if (i == 1)
        {
            k = false;
        }
    }
    // cout << endl;
    printf(k ? "YES\n" : "NO\n");
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