#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e3;
bitset<N> con[N];

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k, t;
    cin >> k >> t;
    for (int i = 0; i < k; i++)
    {
        con[i][i] = true;
    }
    for (int i = 0, a, b; i < t; i++)
    {
        cin >> a >> b;
        --a, --b;
        if (con[b][a])
        {
            cout << a + 1 << " " << b + 1 << endl;
            continue;
        }
        if (con[a][b])
        {
            continue;
        }
        for (int j = 0; j < k; j++)
        {
            if (con[j][a])
            {
                con[j] |= con[b];
            }
        }
    }
    cout << "0 0\n";
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
