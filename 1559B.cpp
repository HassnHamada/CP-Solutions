#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 100;
char str[N];

void run()
{
    int n;
    cin >> n;
    char s = '\0';
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        if (str[i] != '?' && s == '\0')
        {
            s = i & 1 ? "RB"[str[i] == 'R'] : str[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '?')
        {
            if (s == '\0')
            {
                s = i ? "RB"[str[i - 1] == 'R'] : 'R';
            }
            str[i] = s;
            s = "RB"[s == 'R'];
        }
        else
        {
            s = '\0';
        }
        cout << str[i];
    }
    cout << endl;
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