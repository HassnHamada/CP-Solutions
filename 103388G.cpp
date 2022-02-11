#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;
typedef long long int ll;

const ll N = 1e15 + 10;

void run()
{
    map<string, ll> s2n;
    map<ll, string> n2s;
    s2n.emplace("A", 2);
    n2s.emplace(2, "A");
    string s = "AA";
    ll n = 3;
    while (n < N)
    {
        s2n.emplace(s, n);
        n2s.emplace(n, s);
        s.pop_back();
        n += s2n.find(s)->second;
        s.push_back('A');
        s.push_back('A');
    }
    cin >> n;
    s.clear();
    for (auto &&i : n2s)
    {
        while (n % i.first == 0)
        {
            s.append(i.second);
            s.push_back('B');
            n /= i.first;
        }
    }
    cout << (n == 1 ? s : "IMPOSSIBLE") << "\n";
}
int main(int argc, char const *argv[])
{
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}
// 1    ->  B
// 2    ->  AB
// 3    ->  AAB
// 4    ->  ABAB
// 5    ->  AAAB
// 6    ->  AABAB
// 7    ->  IMPOSSIBLE
// 8    ->  AAAAB
// 9    ->  AABAAB
//  A   A   A   A   B
//  A       A   A   B
//  A   A       A   B
//  A   A   A       B
//  A   A   A   A    
//  A       A       B
//  A       A   A    
//  A   A       A    