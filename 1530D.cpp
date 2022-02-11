#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

bool fill(vector<int> &ret, set<int> &sss, int s = 0)
{
    int n = ret.size();
    for (int i = s; i < n; i++)
    {
        if (ret[i])
        {
            continue;
        }
        for (auto &&j : sss)
        {
            if (j == i + 1)
            {
                continue;
            }
            ret[i] = j;
            sss.erase(j);
            if (fill(ret, sss, i + 1))
            {
                return true;
            }
            sss.insert(ret[i]);
        }
    }
    return sss.empty();
}

int testCase(vector<int> &ret)
{
    int n, sat = 0;
    cin >> n;
    ret.resize(n);
    set<int> sss;
    vector<int> gif;
    for (int i = 1; i <= n; i++)
    {
        sss.insert(i);
    }
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        gif.push_back(v);
        if (sss.find(v) == sss.end())
        {
            continue;
        }
        ret[i] = v;
        sat += 1;
        sss.erase(v);
    }
    // cout << sss.size() << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ret[i] << " ";
    // }
    // cout << endl;

    if (sss.size() == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (ret[i])
            {
                continue;
            }
            ret[i] = *sss.begin();
            if (i + 1 == ret[i])
            {
                // swap(ret[i], ret[i ? 0 : n - 1]);
                // sat -= 1;
                for (int j = 0; j < n; j++)
                {
                    if (gif[i] == ret[j])
                    {
                        swap(ret[i], ret[j]);
                        break;
                    }
                }
            }
            break;
        }
    }
    else
    {
        assert(fill(ret, sss));
        // cout << "HI\n";
        // fill(ret, sss);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     if (ret[i])
    //     {
    //         continue;
    //     }
    // }

    return sat;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        vector<int> ans;
        cout << testCase(ans) << endl;
        for (auto &&j : ans)
        {
            cout << j << " \n"[&j == &ans.back()];
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
