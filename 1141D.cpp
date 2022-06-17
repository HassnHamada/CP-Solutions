#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char aaa[N], bbb[N];

void run()
{
    int n;
    scanf("%d%s%s", &n, aaa, bbb);
    map<char, vector<int>> mmm;
    for (int i = 0; i < n; i++)
    {
        mmm[bbb[i]].push_back(i);
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        auto &it = mmm[aaa[i]];
        if (aaa[i] == '?' || it.empty())
        {
            continue;
        }
        ans.emplace_back(i + 1, it.back() + 1);
        aaa[i] = bbb[it.back()] = '!';
        it.pop_back();
    }
    for (int i = 0; i < n; i++)
    {
        if (aaa[i] != '?')
        {
            continue;
        }
        for (char j = 'a'; j <= 'z'; j++)
        {
            auto &it = mmm[j];
            if (it.empty())
            {
                continue;
            }
            ans.emplace_back(i + 1, it.back() + 1);
            aaa[i] = bbb[it.back()] = '!';
            it.pop_back();
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        auto &it = mmm['?'];
        if (aaa[i] == '!' || it.empty())
        {
            continue;
        }
        ans.emplace_back(i + 1, it.back() + 1);
        it.pop_back();
    }
    printf("%d\n", (int)ans.size());
    for (auto &&i : ans)
    {
        printf("%d %d\n", i.first, i.second);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
