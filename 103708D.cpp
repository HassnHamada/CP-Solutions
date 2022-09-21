#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 10, M = 2e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct Mat
{
    int x, y;
    vector<vector<int>> mat;
    Mat(int _x, int _y)
    {
        x = _x;
        y = _y;
        mat = vector<vector<int>>(x, vector<int>(y, 0));
    }

    Mat(int _x, int _y, vector<int> vec)
    {
        assert(_x * _y == (int)vec.size());
        x = _x;
        y = _y;
        mat = vector<vector<int>>(x, vector<int>(y, 0));
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                mat[i][j] = vec[i * x + j];
            }
        }
    }
    Mat operator*(const Mat &other) const
    {
        assert(this->y == other.x);
        Mat ret(this->x, other.y);
        for (int i = 0; i < ret.x; i++)
        {
            for (int j = 0; j < ret.y; j++)
            {
                for (int k = 0; k < y; k++)
                {
                    ret.mat[i][j] = (ret.mat[i][j] + 1ll * mat[i][k] * other.mat[k][j] % MOD) % MOD;
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
    ll sum()
    {
        ll ret = 0;
        for (auto &&i : mat)
        {
            for (auto &&j : i)
            {
                ret = (ret + j) % MOD;
            }
        }
        return ret;
    }
};

Mat mat_pow(Mat b, int p)
{
    assert(b.x == b.y);
    Mat ret(b.x, b.y);
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
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    Mat trn(n, n);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        u -= 1, v -= 1;
        trn.mat[u][v] += 1;
        trn.mat[v][u] += 1;
    }
    Mat bas(1, n);
    bas.mat[0][0] = 1;
    printf("%lld", (bas * mat_pow(trn, k)).sum());
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}