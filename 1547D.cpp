#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

int log(int x)
{
    return 32 - __builtin_clz(x) - 1;
}
int size(int n)
{
    return n ? log(n) + 1 : 0;
}

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
        int n;
        cin >> n;
        for (int i = 0, l = 0, v; i < n; i++)
        {
            cin >> v;
            int w = (l ^ v) & l & ((1 << size(l)) - 1);
            cout << w << " \n"[i + 1 == n];
            l = v | w;
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
