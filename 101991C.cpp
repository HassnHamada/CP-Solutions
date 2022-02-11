#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

struct Price
{
    int s, m, l;
};

map<string, Price> mmm;

void run()
{
    mmm.clear();
    int c, p;
    cin >> c >> p;
    for (int i = 0; i < c; i++)
    {
        string n;
        int s, m, l;
        cin >> n >> s >> m >> l;
        mmm[n] = {s, m, l};
    }
    // map<string, int> ccc;
    int e = 100 / p;
    for (int i = 0; i < p; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        int ans = e;
        if (b[0] == 's')
        {
            ans += mmm[c].s;
        }
        else if (b[0] == 'm')
        {
            ans += mmm[c].m;
        }
        else
        {
            ans += mmm[c].l;
        }
        if (ans % 5 == 1)
        {
            ans -= 1;
        }
        else if (ans % 5 == 4)
        {
            ans += 1;
        }
        cout << a << " " << ans << endl;
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen("coffee.in", "r", stdin);
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
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