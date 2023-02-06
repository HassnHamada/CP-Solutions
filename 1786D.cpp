#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char buf[M];

void run()
{
    int m;
    scanf("%d", &m);
    map<pair<char, char>, set<int>> mmm;
    for (int j = 0; j < m; j++)
    {
        scanf("%s", buf);
        int w = count(buf, buf + 3, 'w');
        int i = count(buf, buf + 3, 'i');
        int n = count(buf, buf + 3, 'n');
        if (w == 1 && i == 1 && n == 1)
        {
            continue;
        }
        if (w == 3 || i == 3 || n == 3)
        {
            if (w == 3)
            {
                mmm[{'w', 'i'}].insert(j);
                mmm[{'w', 'n'}].insert(j);
            }
            if (i == 3)
            {
                mmm[{'i', 'w'}].insert(j);
                mmm[{'i', 'n'}].insert(j);
            }
            if (n == 3)
            {
                mmm[{'n', 'w'}].insert(j);
                mmm[{'n', 'i'}].insert(j);
            }
        }
        else
        {
            assert(w == 2 || i == 2 || n == 2);
            assert(w == 1 || i == 1 || n == 1);
            assert(w == 0 || i == 0 || n == 0);
            if (w == 2)
            {
                if (i == 0)
                {
                    mmm[{'w', 'i'}].insert(j);
                }
                else
                {
                    mmm[{'w', 'n'}].insert(j);
                }
            }
            if (i == 2)
            {
                if (w == 0)
                {
                    mmm[{'i', 'w'}].insert(j);
                }
                else
                {
                    mmm[{'i', 'n'}].insert(j);
                }
            }
            if (n == 2)
            {
                if (w == 0)
                {
                    mmm[{'n', 'w'}].insert(j);
                }
                else
                {
                    mmm[{'n', 'i'}].insert(j);
                }
            }
        }
    }
    vector<tuple<int, char, int, char>> ans;
    while (true)
    {
        bool again = false;
        for (auto &&[i, j] : mmm)
        {
            pair<char, char> k = {i.second, i.first};
            while (!j.empty() && !mmm[k].empty())
            {
                ans.emplace_back(*j.begin(), i.first, *mmm[k].begin(), i.second);
                j.erase(j.begin());
                mmm[k].erase(mmm[k].begin());
            }
            if (k.first == 'w')
            {
                k.second = k.second == 'i' ? 'n' : 'i';
            }
            else if (k.first == 'i')
            {
                k.second = k.second == 'w' ? 'n' : 'w';
            }
            else if (k.first == 'n')
            {
                k.second = k.second == 'w' ? 'i' : 'w';
            }
            while (!j.empty() && !mmm[k].empty())
            {
                ans.emplace_back(*j.begin(), i.first, *mmm[k].begin(), i.second);
                j.erase(j.begin());
                mmm[{i.first, k.second}].insert(*mmm[k].begin());
                mmm[k].erase(mmm[k].begin());
                again = true;
            }
        }
        if (!again)
        {
            break;
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto &&[i, j, k, l] : ans)
    {
        printf("%d %c %d %c\n", i + 1, j, k + 1, l);
    }
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