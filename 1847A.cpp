#include <bits/stdc++.h>
// #include <stdio.h>
// #include <vector>
using namespace std;
typedef long long ll;

// const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> vec(n);
    for (auto &&i : vec)
    {   
        scanf("%d", &i);
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        vec[i] = abs(vec[i] - vec[i + 1]);
        ans += vec[i];
    }
    sort(vec.begin(), vec.end() - 1, greater<int>());
    for (int i = 0; i < k - 1; i++)
    {
        ans -= vec[i];
    }
    printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}