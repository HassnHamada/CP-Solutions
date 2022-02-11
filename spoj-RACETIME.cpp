#include <bits/stdc++.h>
// #include <chrono>
// #include "./stdc++.h"
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10, SQ = 450;
int bit2[SQ][N], inp[N], qry[N][4], com[2 * N], n, q;

void add2(int x, int y, int v)
{
    for (int i = x + 1; i < SQ; i += i & -i)
    {
        for (int j = y + 1; j < N; j += j & -j)
        {
            bit2[i - 1][j - 1] += v;
        }
    }
}

int get2(int x, int y)
{
    int ret = 0;
    for (int i = x + 1; i; i -= i & -i)
    {
        for (int j = y + 1; j; j -= j & -j)
        {
            ret += bit2[i - 1][j - 1];
        }
    }
    return ret;
}

int bucket(int ind)
{
    // return (ind + SQ - 1) / SQ;
    return ind / SQ;
}

int calc(int i, int v)
{
    int ret = get2(bucket(i), v);
    // cout << i << " " << v << " " << ret << endl;
    for (int j = i + 1; j < n && bucket(j) == bucket(i); j++)
    {
        ret -= (int)(inp[j] <= v);
        // cout << "HI " << ret << " " << j << " " << inp[j] << endl;
    }
    return ret;
}
// int calc(int e, int v)
// {
//     // cout << e << " " << v << endl;
//     int b = (e + SQ - 1) / SQ, ret = 0;
//     for (int i = (b - 1) * SQ + 1; i <= e; i++)
//     {
//         // cout << i << " " << e << endl;
//         ret += (inp[i] <= v);
//     }
//     // cout << ret << " " << get(b - 1, v) << endl;
//     return ret + get2(b - 1, v);
// }

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
        com[i - 1] = inp[i];
    }
    for (int i = 0; i < q; i++)
    {
        char c;
        cin >> c;
        qry[i][0] = c == 'C';
        int s = 2 + qry[i][0];
        for (int j = 1; j <= s; j++)
        {
            cin >> qry[i][j];
        }
        com[n + i] = qry[i][s];
    }
    sort(com, com + n + q);
    int s = unique(com, com + n + q) - com;
    for (int i = 0; i < n; i++)
    {
        inp[i] = lower_bound(com, com + s, inp[i]) - com;
        add2(bucket(i), inp[i], 1);
    }
    for (int i = 0; i < q; i++)
    {
        qry[i][2 + qry[i][0]] = lower_bound(com, com + s, qry[i][2 + qry[i][0]]) - com;
        if (qry[i][0])
        {
            qry[i][1]--, qry[i][2]--;
            // cout << calc(qry[i][2], qry[i][3]) << " " << (qry[i][1] > 1 ? calc(qry[i][1] - 1, qry[i][3]) : 0) << endl;
            cout << calc(qry[i][2], qry[i][3]) - (qry[i][1] ? calc(qry[i][1] - 1, qry[i][3]) : 0) << endl;
        }
        else
        {
            qry[i][1]--;
            add2(bucket(qry[i][1]), inp[qry[i][1]], -1);
            add2(bucket(qry[i][1]), inp[qry[i][1]] = qry[i][2], 1);
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}