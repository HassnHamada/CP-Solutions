#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;
const int N = 100;
int n, m, k, mon[N], pol[N];

int fill(int *from, int s, int sz, vector<int> &to)
{
    for (int i = s; i < sz; i++)
    {
        if (from[i] && from[i] > k)
        {
            return i;
        }
        to.push_back(from[i]);
        k += from[i] == 0;
    }
    return sz;
}

void work(int i, int j, int c, vector<int> &ans)
{
    while (true)
    {
        int sz = ans.size();
        i = fill(mon, i, n, ans);
        j = fill(pol, j, m, ans);
        if (ans.size() == sz)
        {
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> k >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> mon[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> pol[i];
        }
        vector<int> ans;
        work(0, 0, k, ans);

        // for (auto &&i : ans)
        // {
        //     cout << i << " \n"[&i == &ans.back()];
        // }
        if (ans.size() == n + m)
        {
            for (auto &&i : ans)
            {
                cout << i << " \n"[&i == &ans.back()];
            }
        }
        else
        {
            cout << "-1\n";
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
