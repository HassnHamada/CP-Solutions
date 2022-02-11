#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10;
int ene[N], gre[N];

void run()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        ene[i] = c == '1';
    }
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        gre[i] = c == '1';
    }
    for (int i = 0, s = 1; i < n; i++)
    {
        if (!gre[i])
        {
            s = ((s & 1) << 1) + 1;
        }
        else if ((s & 2) && ene[i - 1])
        {
            ans += 1;
            s = ((s & 1) << 1) + 1;
        }
        else if ((s & 1) && !ene[i])
        {
            ans += 1;
            s = 1;
        }
        else if (i + 1 < n && ene[i + 1])
        {
            ans += 1;
            s = (s & 1) << 1;
        }
        else
        {
            s = ((s & 1) << 1) + 1;
        }
        assert(s >= 0 && s <= 3);
    }
    cout << ans << endl;
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
