#include <bits/stdc++.h>
// #include <chrono>
// #include "./stdc++.h"
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 4e5 + 10, SQ = 450;
int inp[N], qry[N][2], com[N];

class BIT
{
private:
    int bit[SQ][N], sq, n;
    int bucket(int x);

public:
    BIT();
    BIT(int sz);
    void add(int x, int y, int v);
    int get(int x, int y);
    int calc(int i, int v);
};

BIT::BIT()
{
    this->n = N;
    this->sq = SQ;
    memset(this->bit, 0, sizeof(this->bit));
}

BIT::BIT(int sz)
{
    this->n = sz;
    this->sq = ceil(sqrt(this->n));
    for (int i = 0; i < this->sq; i++)
    {
        memset((int *)(this->bit + i), 0, this->n * sizeof(this->bit[0][0]));
    }
}

void BIT::add(int x, int y, int v)
{
    for (int i = this->bucket(x) + 1; i <= this->sq; i += i & -i)
    {
        for (int j = y + 1; j <= this->n; j += j & -j)
        {
            this->bit[i - 1][j - 1] += v;
        }
    }
}

int BIT::bucket(int x)
{
    return x / this->sq;
}

int BIT::get(int x, int y)
{
    int ret = 0;
    for (int i = this->bucket(x) + 1; i; i -= i & -i)
    {
        for (int j = y + 1; j; j -= j & -j)
        {
            ret += this->bit[i - 1][j - 1];
        }
    }
    return ret;
}

int BIT::calc(int i, int v)
{
    int ret = get(i, v);
    for (int j = i + 1; j < this->n && this->bucket(j) == this->bucket(i); j++)
    {
        ret -= (int)(inp[j] <= v);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
        com[i] = inp[i];
    }
    for (int i = 0; i < q; i++)
    {
        cin >> qry[i][0] >> qry[i][1];
        com[n + i] = qry[i][1];
    }
    sort(com, com + n + q);
    int s = unique(com, com + n + q) - com;
    BIT *bit = new BIT(n);
    for (int i = 0; i < n; i++)
    {
        inp[i] = lower_bound(com, com + s, inp[i]) - com;
        bit->add(i, inp[i], 1);
    }
    for (int i = 0; i < q; i++)
    {
        qry[i][1] = lower_bound(com, com + s, qry[i][1]) - com;
        cout << (qry[i][0] ? bit->calc(qry[i][0] - 1, qry[i][1]) : 0) - (qry[i][0] && qry[i][1] ? bit->calc(qry[i][0] - 1, qry[i][1] - 1) : 0) << endl;
        bit->add(qry[i][0], inp[qry[i][0]], -1);
        bit->add(qry[i][0], inp[qry[i][0]] = qry[i][1], 1);
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}