#include <bits/stdc++.h>
// #include <chrono>
// #include "./stdc++.h"
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

set<pair<int, int>> c1, c2, c3;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec[j][i];
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (vec[j][1] == 1)
        {
            c1.insert({vec[j][0], vec[j][2]});
        }
        else if (vec[j][1] == 2)
        {
            c2.insert({vec[j][0], vec[j][2]});
        }
        else if (vec[j][1] == 3)
        {
            c3.insert({vec[j][0], vec[j][2]});
        }
        else
        {
            assert(false);
        }
        if (vec[j][2] == 1)
        {
            c1.insert({vec[j][0], vec[j][1]});
        }
        else if (vec[j][2] == 2)
        {
            c2.insert({vec[j][0], vec[j][1]});
        }
        else if (vec[j][2] == 3)
        {
            c3.insert({vec[j][0], vec[j][1]});
        }
        else
        {
            assert(false);
        }
    }
    int m;
    cin >> m;
    for (int i = 0, v; i < m; i++)
    {
        cin >> v;
        pair<int, int> it;
        if (v == 1)
        {
            if (c1.empty())
            {
                cout << -1 << " \n"[i + 1 == m];

                continue;
            }
            it = *c1.begin();
            c1.erase(it);
        }
        else if (v == 2)
        {
            if (c2.empty())
            {
                cout << -1 << " \n"[i + 1 == m];

                continue;
            }
            it = *c2.begin();
            c2.erase(it);
        }
        else if (v == 3)
        {
            if (c3.empty())
            {
                cout << -1 << " \n"[i + 1 == m];

                continue;
            }
            it = *c3.begin();
            c3.erase(it);
        }
        else
        {
            assert(false);
        }
        // cout << it.first << " " << it.second << endl;
        if (it.second == 1)
        {
            c1.erase({it.first, v});
        }
        else if (it.second == 2)
        {
            c2.erase({it.first, v});
        }
        else if (it.second == 3)
        {
            c3.erase({it.first, v});
        }
        else
        {
            // cout << it.second;
            assert(false);
        }
        cout << it.first << " \n"[i + 1 == m];
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}