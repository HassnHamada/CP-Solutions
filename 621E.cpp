#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

const int N = 10, M = 65, L = 4, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct Mat
{
    ull m;
    int x, y;
    vector<vector<ull>> mat;
    Mat(int _x, int _y, ull _m = MOD)
    {
        x = _x;
        y = _y;
        m = _m;
        mat = vector<vector<ull>>(x, vector<ull>(y, 0));
    }

    Mat(int _x, int _y, vector<ull> vec, ull _m = MOD)
    {
        assert(_x * _y == (int)vec.size());
        x = _x;
        y = _y;
        m = _m;
        mat = vector<vector<ull>>(x, vector<ull>(y, 0));
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                mat[i][j] = vec[i * x + j] % m;
            }
        }
    }
    Mat operator*(const Mat &other) const
    {
        assert(y == other.x);
        assert(m == other.m);
        Mat ret(x, other.y, m);
        for (int i = 0; i < ret.x; i++)
        {
            for (int j = 0; j < ret.y; j++)
            {
                for (int k = 0; k < y; k++)
                {
                    // assert(ret.mat[i][j] + mat[i][k] * other.mat[k][j] < m);
                    ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * other.mat[k][j] % m) % m;
                }
            }
        }
        return ret;
    }
    void identity()
    {
        assert(x == y);
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                mat[i][j] = i == j;
            }
        }
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

    ll sum()
    {
        ll ret = 0;
        for (auto &&i : mat)
        {
            for (auto &&j : i)
            {
                ret = (ret + j) % m;
            }
        }
        return ret;
    }
};

Mat mat_pow(Mat b, int p)
{
    assert(b.x == b.y);
    Mat ret(b.x, b.y, b.m);
    ret.identity();
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

int frq[N];

void run()
{
    int n, b, k, x;
    scanf("%d%d%d%d", &n, &b, &k, &x);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        frq[v]++;
    }
    vector<ull> tem(x * x, 0);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int l = (i * 10 + j) % x;
            tem[i * x + l] += frq[j];
        }
    }
    Mat t(x, x, tem, MOD);
    tem.clear();
    tem.resize(x);
    for (int i = 0; i < x; i++)
    {
        tem[i] = i == 0;
    }
    Mat i(1, x, tem, MOD);
    printf("%llu\n", (i * mat_pow(t, b)).mat[0][k]);
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}