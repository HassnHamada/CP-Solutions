#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e3 + 10;
int ans[N];

void run()
{
    int n;
    cin >> n;
    cout << ans[--n] << endl;
}

void pre()
{
    for (int i = 0, c = 1; i < N; i++)
    {
        ans[i] = c;
        do
        {
            c++;
        } while (c % 3 == 0 || c % 10 == 3);
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
    // cout << setprecision(10) << fixed;
    pre();
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