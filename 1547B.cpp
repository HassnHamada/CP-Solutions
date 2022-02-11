#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

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
        string s;
        cin >> s;
        int i = 0, j = s.size() - 1, ok = 1;
        for (int t = j; ~t && ok; t--)
        {
            // cout << s[i] << endl;
            if (s[i] - 'a' == t)
            {
                i += 1;
            }
            else if (s[j] - 'a' == t)
            {
                j -= 1;
            }
            else
            {
                ok = 0;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
