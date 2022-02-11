#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

ll dis(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll n, m, i, j, maxDis = 0;
        pair<ll, ll> ans1, ans2;
        scanf("%lld%lld%lld%lld", &n, &m, &i, &j);
        vector<pair<ll, ll>> vec = {{1, 1}, {1, m}, {n, 1}, {n, m}};
        for (auto &&ii : vec)
        {
            for (auto &&jj : vec)
            {
                ll newDis = dis({i, j}, ii) + dis(ii, jj) + dis(jj, {i, j});
                if (newDis >= maxDis)
                {
                    maxDis = newDis;
                    ans1 = ii;
                    ans2 = jj;
                }
            }
        }
        printf("%lld %lld %lld %lld\n", ans1.first, ans1.second, ans2.first, ans2.second);
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}