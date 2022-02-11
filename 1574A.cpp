#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

int n, c;

void dfs(int a, int b, string &s)
{
    if (s.size() == 2 * n)
    {
        cout << s << endl;
        assert(c++ < n);
        return;
    }
    if (a < n && c < n)
    {
        s.push_back('(');
        dfs(a + 1, b, s);
        s.pop_back();
    }
    if (b < a && c < n)
    {
        s.push_back(')');
        dfs(a, b + 1, s);
        s.pop_back();
    }
}

void run()
{
    c = 0;
    cin >> n;
    string s;
    dfs(0, 0, s);
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
