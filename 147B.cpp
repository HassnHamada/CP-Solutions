// #include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;
// typedef long long int ll;

const int EMP = INT32_MIN;

struct Mat
{
    int x, y;
    vector<vector<int>> mat;
    Mat(int a, int b)
    {
        this->x = a;
        this->y = b;
        this->mat = vector<vector<int>>(a, vector<int>(b, EMP));
    }
    Mat operator*(const Mat &other)
    {
        // assert(this->y == other.x);
        Mat ret(this->x, other.y);
        for (int i = 0; i < ret.x; i++)
        {
            for (int j = 0; j < ret.y; j++)
            {
                ret.mat[i][j] = max(other.mat[i][j], this->mat[i][j]);
                for (int k = 0; k < (this->y); k++)
                {
                    if (this->mat[i][k] == EMP || other.mat[k][j] == EMP)
                    {
                        continue;
                    }
                    ret.mat[i][j] = max(ret.mat[i][j], this->mat[i][k] + other.mat[k][j]);
                }
            }
        }
        return ret;
    }
};

Mat my_pow(Mat b, int p)
{
    Mat ret(b.x, b.x);
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

bool ok(Mat &mat, int n)
{
    Mat ret = my_pow(mat, n);
    for (int i = 0; i < ret.x; i++)
    {
        if (ret.mat[i][i] > 0)
        {
            return true;
        }
    }
    return false;
}

void run()
{
    int n, m;
    cin >> n >> m;
    Mat mat(n, n);
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v >> mat.mat[--u][--v] >> mat.mat[v][u];
    }
    int l = 0, h = n + 1;
    while (l < h)
    {
        int mid = l + (h - l) / 2;
        if (ok(mat, mid))
        {
            h = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << (l == n + 1 ? 0 : l) << endl;
}

int main(int argc, char const *argv[])
{
    freopen(".\\_input.txt", "r", stdin);
    freopen(".\\_output.txt", "w", stdout);
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
    return 0;
}