#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
#include <vector>
#include <utility>
#include <assert.h>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    ll tot = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        tot += arr[i];
    }
    bool ok = tot % n == 0;
    if (ok)
    {
        int tar = tot / n;
        map<int, vector<pair<int, int>>> mmm;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == tar)
            {
                mmm[i].emplace_back(-1, -1);
                continue;
            }
            for (int j = 0; j <= 30; j++)
            {
                int x = j ? 1 << (j - 1) : j;
                int y = arr[i] + x - tar;
                if (y == 0 || (y > 0 && __builtin_popcount(y) == 1))
                {
                    mmm[i].emplace_back(x, y);
                }
            }
            if (mmm[i].empty())
            {
                ok = false;
                break;
            }
            // assert((int)vec.size() == i + 1);
        }
        if (ok)
        {
            multiset<int> take, give;
            for (auto &&i : mmm)
            {
                for (auto &&j : i.second)
                {
                    printf("%d %d\n", j.first, j.second);
                    take.insert(j.first);
                    give.insert(j.second);
                }
                printf("---\n");
            }
            for (auto &&i : take)
            {
                auto it = give.find(i);
                if (it == give.end())
                {
                    it = give.find(-1);
                }
                if (it == give.end())
                {
                    ok = false;
                    break;
                }
                give.erase(it);
            }
        }
    }
    printf(ok ? "YES\n" : "NO\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}