#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct Mat
{
    int x, y, m;
    vector<vector<int>> mat;
    Mat(int _x, int _y, int _m = MOD)
    {
        x = _x;
        y = _y;
        m = _m;
        mat = vector<vector<int>>(x, vector<int>(y, 0));
    }

    Mat(int _x, int _y, vector<int> vec, int _m = MOD)
    {
        assert(_x * _y == (int)vec.size());
        x = _x;
        y = _y;
        m = _m;
        mat = vector<vector<int>>(x, vector<int>(y, 0));
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
                    ret.mat[i][j] = (ret.mat[i][j] + 1ll * mat[i][k] * other.mat[k][j] % m) % m;
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

int fib(int a, int b, int p, int m)
{
    Mat i(1, 2, {a, b}, m);
    Mat t(2, 2, {0, 1, 1, 1}, m);
    return (i * mat_pow(t, p)).mat[0][0];
}

void run()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        printf("%d\n", fib(0, 1, n, 1 << m));
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}