#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e3 + 10;
int mat[N][N], inp[N / 2][2], com[N];

void run()
{
    for (int i = 0; i < N; i++)
    {
        memset((int *)(mat + i), 0, N);
    }
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> inp[i][0] >> inp[i][1];
        com[2 * i] = inp[i][0];
        com[2 * i + 1] = inp[i][1];
    }
    sort(com, com + 2 * n);
    int m = unique(com, com + 2 * n) - com, nn = 0, mm = 0;
    for (int i = 0; i < k; i++)
    {
        inp[i][0] = lower_bound(com, com + m, inp[i][0]) - com + 1;
        inp[i][1] = lower_bound(com, com + m, inp[i][1]) - com + 1;
        mat[inp[i][0]][inp[i][1]] += 1;
        nn = max(nn, inp[i][0]);
        mm = max(mm, inp[i][1]);
    }
    int ans = 0;
    for (int i = 0; i <= nn; i++)
    {
        for (int j = 0; j <= mm; j++)
        {
            mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
            
        }
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("baklava.in", "r", stdin);
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(5) << fixed;
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