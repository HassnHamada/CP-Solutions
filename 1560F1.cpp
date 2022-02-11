#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int Mx = 2e9 + 10;
int ans;
set<int> one, two;

void run()
{
    int n, k;
    cin >> n >> k;
    cout << *(k & 1 ? one : two).lower_bound(n) << endl;
}

void dfsOne(int n, ll c)
{
    if (c > Mx)
    {
        return;
    }
    one.insert(c);
    dfsOne(n, c * 10 + n);
}

void dfsTwo(int n1, int n2, ll c)
{
    if (c > Mx)
    {
        return;
    }
    two.insert(c);
    dfsTwo(n1, n2, c * 10 + n1);
    dfsTwo(n1, n2, c * 10 + n2);
}

void pre()
{
    for (int i = 1; i < 10; i++)
    {
        dfsOne(i, i);
    }
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            dfsTwo(i, j, i);
        }
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
    // cout << *two.lower_bound(177890) << endl;
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