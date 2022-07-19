#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], ans[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; i++)
    {
        vec.push_back({i / (arr[i] + 1) + 1, i});
    }
    sort(vec.begin(), vec.end());
    set<pair<int, int>> sss;
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j < n && vec[j].first == i)
        {
            int k = vec[j++].second;
            sss.insert({arr[k] ? k / arr[k] : n, k});
        }
        ans[sss.begin()->second] = i;
        sss.erase(sss.begin());
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d%c", ans[i], " \n"[i == n]);
    }
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