#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 3e2 + 10;
int grd[N][N];
struct Mat
{
    int x, y;
    vector<vector<double>> mat;
    Mat(int a, int b)
    {
        mat = vector<vector<double>>(x = a, vector<double>(y = b, 0.0));
    }
    Mat operator*(Mat &other)
    {
        assert(this->y == other.x);
        Mat ret(this->x, other.y);
        for (int i = 0; i < ret.x; i++)
        {
            for (int j = 0; j < ret.y; j++)
            {
                ret.mat[i][j] = this->mat[i][j] * (1 - other.mat[i][j]) + (1 - this->mat[i][j]) * other.mat[i][j];
                // for (int k = 0; k < other.x; k++)
                // {
                //     ret.mat[i][j] += this->mat[i][k] * other.mat[k][j];
                // }
            }
        }
        return ret;
    }
    void prn()
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

Mat my_pow(Mat b, int p)
{
    assert(b.x == b.y);
    Mat ret(b.x, b.x);
    // for (int i = 0; i < b.x; i++)
    // {
    //     ret.mat[i][i] = 1;
    // }
    while (p)
    {
        if (p & 1)
        {
            ret = ret * b;
        }
        b = b * b;
        p /= 2;
    }
    return ret;
}

void run()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grd[i][j];
            // grd[i][j] = (i ? grd[i - 1][j] : 0) + (j ? grd[i][j - 1] : 0) - (i && j ? grd[i - 1][j - 1] : 0);
        }
    }
    double m = 1ll * n * n * (n + 1) * (n + 1) / 4;
    Mat mat(n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat.mat[i][j] = ((n - i - 1) * (n - j - 1) * i * j + (n - i - 1) * i * n + (n - j - 1) * j * n + n * n) / m;
        }
    }
    // mat.prn();
    mat = my_pow(mat, k);
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += grd[i][j] ? 1 - mat.mat[i][j] : mat.mat[i][j];
        }
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen("fetiera.in", "r", stdin);
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(5) << fixed;
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
