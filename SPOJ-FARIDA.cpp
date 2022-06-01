#include <bits/stdc++.h>
// #include "./stdc++.h"
using namespace std;
typedef long long int ll;

auto &in = std::cin;
auto &out = std::cout;

// std::ifstream in("input.txt");
// std::ofstream out("output.txt");

int main(int argc, char const *argv[])
{
    ll t;
    in >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll a = 0, b = 0, n;
        in >> n;
        for (int i = 0; i < n; i++)
        {
            ll v;
            in >> v;
            v = max(v + b, a);
            b = a;
            a = v;
        }

        out << "Case " << i << ": " << max(a, b) << endl;
    }

    return 0;
}