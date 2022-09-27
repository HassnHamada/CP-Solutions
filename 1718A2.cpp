#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        arr[i] = arr[i - 1] ^ arr[i];
    }
    int ans = n;
    set<int> sss;
    sss.insert(0);
    for (int i = 1; i <= n; i++)
    {
        if (sss.find(arr[i]) != sss.end())
        {
            ans -= 1;
            sss.clear();
        }
        sss.insert(arr[i]);
    }

    printf("%d\n", ans);
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