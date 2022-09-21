#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

const int N = 8, M = 65, L = 4, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

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

int dx[] = {-2, -1, 1, 2};
int dy[] = {1, 2, 2, 1};

void run()
{
    vector<ull> tem(M * M, 0);
    for (int j = 0; j < M - 1; j++)
    {
        for (int l = 0; l < L; l++)
        {
            int x = j % N + dx[l], y1 = j / N + dy[l], y2 = j / N - dy[l];
            int d1 = x + y1 * N,
                d2 = x + y2 * N;
            if (x >= 0 && x < N && y1 >= 0 && y1 < N)
            {
                assert(j + M * d1 >= 0 && j + M * d1 < M * M);
                tem[j + M * d1] = 1;
            }
            if (x >= 0 && x < N && y2 >= 0 && y2 < N)
            {
                assert(j + M * d2 >= 0 && j + M * d2 < M * M);
                tem[j + M * d2] = 1;
            }
        }
    }
    for (int i = 1; i <= M; i++)
    {
        tem[i * M - 1] = 1;
    }
    Mat t(M, M, tem, 1ll << 32);
    tem.clear();
    tem.resize(M);
    for (int i = 0; i < M; i++)
    {
        tem[i] = i == 0;
    }
    Mat i(1, M, tem, 1ll << 32);
    int k;
    scanf("%d", &k);
    printf("%lld\n", (i * mat_pow(t, k)).sum());
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