#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int MOD = 1e9 + 7;

struct Mat
{
    int x, y;
    vector<vector<ll>> mat;
    Mat(ll a, ll b)
    {
        this->x = a;
        this->y = b;
        this->mat = vector<vector<ll>>(a, vector<ll>(b, 0));
    }
    Mat operator*(const Mat &other)
    {
        assert(this->y == other.x);
        Mat ret(this->x, other.y);
        for (ll i = 0; i < ret.x; i++)
        {
            for (ll j = 0; j < ret.y; j++)
            {
                for (ll k = 0; k < other.x; k++)
                {
                    ret.mat[i][j] = (ret.mat[i][j] + this->mat[i][k] * other.mat[k][j] % MOD) % MOD;
                }
            }
        }
        return ret;
    }
};

Mat my_pow(Mat b, ll p)
{
    assert(b.x == b.y);
    Mat ret(b.x, b.x);
    for (int i = 0; i < b.x; i++)
    {
        ret.mat[i][i] = 1;
    }
    while (p)
    {
        // cout << p << endl;
        if (p & 1)
        {
            ret = ret * b;
        }
        b = b * b;
        p /= 2;
    }
    return ret;
}

ll my_pow(ll b, ll p, ll m = MOD)
{
    ll ret = 1;
    while (p)
    {
        if (p & 1)
        {
            ret = ret * b % m;
        }
        b = b * b % m;
        p /= 2;
    }
    return ret;
}

void run()
{
    int n, k;
    cin >> n >> k;
    Mat mat(n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat.mat[i][j];
        }
    }
    mat = my_pow(mat, k);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << mat.mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = 0, q = my_pow(my_pow(1e6, k), MOD - 2);
    for (int i = 0; i < n; i++)
    {
        ans = (ans + (i + 1) * mat.mat[0][i] % MOD * q % MOD) % MOD;
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
    // cin >> t;
    while (t--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}