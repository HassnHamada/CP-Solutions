#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e3 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int n, k;
    scanf("%d%d\n", &n, &k);
    map<int, vector<int>> mmm;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        mmm[arr[i] % k].push_back(i);
    }
    ll ans = 0;
    while (mmm.size())
    {
        auto it = mmm.begin();
        if (it->second.empty())
        {
            mmm.erase(it);
            continue;
        }
        auto it2 = mmm.lower_bound(k - it->first);
        if (it2 == mmm.end() || it == it2)
        {
            for (int i = 0; i < (int)it->second.size() / 2; i++)
            {
                ans += (arr[it->second[2 * i]] + arr[it->second[2 * i + 1]]) / k;
            }
            if (it->second.size() & 1)
            {
                // assert(it != it2);
                for (int i = 1;; i++)
                {
                    it2 = mmm.lower_bound(it->first + i);
                    // assert(it2 != mmm.end());
                    if (it2->second.size() == 0)
                    {
                        mmm.erase(it2);
                    }
                    else
                    {
                        break;
                    }
                }
                ans += (arr[it->second.back()] + arr[it2->second.back()]) / k;
                it2->second.pop_back();
            }
        }
        else
        {
            if (it->second.size() > it2->second.size())
            {
                swap(it, it2);
            }
            for (auto &&i : it->second)
            {
                int j = it2->second.back();
                ans += (arr[i] + arr[j]) / k;
                it2->second.pop_back();
            }
        }
        mmm.erase(it);
    }
    printf("%lld\n", ans);
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
