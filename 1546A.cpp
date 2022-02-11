#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, s1 = 0, s2 = 0, m = 0;
        cin >> n;
        vector<int> vec1(n), vec2(n), inc, dec;
        for (auto &&i : vec1)
        {
            cin >> i;
            s1 += i;
        }
        for (auto &&i : vec2)
        {
            cin >> i;
            s2 += i;
        }
        if (s1 != s2)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            if (vec1[i] == vec2[i])
                continue;
            (vec1[i] > vec2[i] ? dec : inc).push_back(i);
            m += (vec1[i] > vec2[i] ? vec1[i] - vec2[i] : 0);
        }
        cout << m << endl;
        for (int i = 0; i < m; i++)
        {
            int a = inc.back(), b = dec.back();
            vec1[a]++;
            vec1[b]--;
            if (vec1[a] == vec2[a])
            {
                inc.pop_back();
            }
            if (vec1[b] == vec2[b])
            {
                dec.pop_back();
            }
            cout << ++b << " " << ++a << endl;
        }
        assert(inc.empty() && dec.empty());
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
