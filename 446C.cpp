#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 19, M = 6, MOD = 1e9 + 9, HV = 151, INF = 0x3f3f3f3f;

int arr[N], F[N], tre[N << 1];
int n, m;
pair<int, int> lz[N << 1];

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
    void prn()
    {
        for (auto &&i : mat)
        {
            for (auto &&j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << "------------\n";
    }
};

vector<Mat> T;

Mat my_pow(Mat b, int p)
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

Mat fib(int a, int b, int p)
{
    Mat i(1, 2, {a, b});
    return i * T[p];
}

void build(int i = 0, int s = 0, int e = n - 1)
{
    if (s == e)
    {
        tre[i] = arr[s];
        return;
    }
    int l = 2 * i + 1, r = l + 1, m = (e - s) / 2 + s;
    build(l, s, m);
    build(r, m + 1, e);
    tre[i] = (tre[l] + tre[r]) % MOD;
}

void pd(int i, int s, int e)
{
    assert(s != e);
    int l = 2 * i + 1, r = l + 1, m = (e - s) / 2 + s;
    auto f = fib(lz[i].first, lz[i].second, m - s + 1);
    int a = f.mat[0][0],
        b = f.mat[0][1],
        c = fib(a, b, e - m + 1).mat[0][0];
    tre[l] = ((tre[l] + b) % MOD - lz[i].second + MOD) % MOD;
    tre[r] = ((tre[r] + c) % MOD - b + MOD) % MOD;
    if (s < m)
    {
        lz[l].first = (lz[l].first + lz[i].first) % MOD;
        lz[l].second = (lz[l].second + lz[i].second) % MOD;
    }
    if (m + 1 < e)
    {
        lz[r].first = (lz[r].first + a) % MOD;
        lz[r].second = (lz[r].second + b) % MOD;
    }
    lz[i].first = lz[i].second = 0;
}

void add(int qs, int qe, int i = 0, int s = 0, int e = n - 1)
{
    if (s > qe || e < qs)
    {
        return;
    }
    if (s >= qs && e <= qe)
    {
        tre[i] = ((tre[i] + F[e - qs + 2]) % MOD - F[s - qs + 1] + MOD) % MOD;
        lz[i].first = (lz[i].first + F[s - qs]) % MOD;
        lz[i].second = (lz[i].second + F[s - qs + 1]) % MOD;
        return;
    }
    if (lz[i].first || lz[i].second)
    {
        pd(i, s, e);
    }
    int l = 2 * i + 1, r = l + 1, m = (e - s) / 2 + s;
    add(qs, qe, l, s, m);
    add(qs, qe, r, m + 1, e);
    tre[i] = (tre[l] + tre[r]) % MOD;
}

int get(int qs, int qe, int i = 0, int s = 0, int e = n - 1)
{
    if (s > qe || e < qs)
    {
        return 0;
    }
    if (s >= qs && e <= qe)
    {
        return tre[i];
    }
    if (lz[i].first || lz[i].second)
    {
        pd(i, s, e);
    }
    int l = 2 * i + 1, r = l + 1, m = (e - s) / 2 + s;
    return (get(qs, qe, l, s, m) + get(qs, qe, r, m + 1, e)) % MOD;
}

void run()
{
    F[0] = F[1] = 1;
    for (int i = 2; i < N; i++)
    {
        F[i] = (F[i - 1] + F[i - 2]) % MOD;
    }
    T.emplace_back(2, 2);
    T.back().identity();
    for (int i = 1; i < N; i++)
    {
        Mat t(2, 2, {0, 1, 1, 1});
        T.push_back(T.back() * t);
    }

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    build();
    while (m--)
    {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1)
        {
            add(l - 1, r - 1);
        }
        else
        {
            printf("%d\n", get(l - 1, r - 1));
        }
    }
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