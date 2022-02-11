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
    // cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        int h, w;
        cin >> h >> w;
        vector<vector<int>> mat(h, vector<int>(w));
        for (int i = 0; i < w; i += 2)
        {
            mat[0][i] = mat[h - 1][i] = 1;
        }
        for (int i = 2; i < h - 2; i += 2)
        {
            mat[i][0] = mat[i][w - 1] = 1;
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cout << mat[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
