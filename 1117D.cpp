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

Mat mat_pow(Mat b, ll p)
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

void run()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> tem(m * m);
    for (int j = 0; j < m - 1; j++)
    {
        tem[(j + 1) * m + j] = 1;
    }
    tem[m - 1] = tem[m * m - 1] = 1;
    Mat t(m, m, tem, MOD);
    tem.clear();
    tem.resize(m);
    for (auto &&j : tem)
    {
        j = 1;
    }
    Mat i(1, m, tem, MOD);
    printf("%d\n", (i * mat_pow(t, n)).mat[0][0]);
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