#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10;
int inp[N], com[3 * N];

struct QUERIES
{
    char c;
    int v, w;
} que[N];

struct BIT
{
    int arr[3 * N];
    void add(int p, int v)
    {
        for (++p; p <= 3 * N; p += p & -p)
        {
            arr[p - 1] += v;
        }
    }

    int get(int p)
    {
        int ret = 0;
        for (++p; p; p -= p & -p)
        {
            ret += arr[p - 1];
        }
        return ret;
    }
} bit;

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
    int sz = n;
    for (int i = 0; i < q; i++)
    {
        cin >> que[i].c >> que[i].v >> que[i].w;
        if (que[i].c == '?')
        {
            com[sz++] = --que[i].v;
        }
        com[sz++] = que[i].w;
    }
    sort(com, com + sz);
    sz = unique(com, com + sz) - com;
    for (int i = 0; i < n; i++)
    {
        inp[i] = lower_bound(com, com + sz, inp[i]) - com;
        bit.add(inp[i], 1);
    }
    for (int i = 0; i < q; i++)
    {
        if (que[i].c == '?')
        {
            que[i].v = lower_bound(com, com + sz, que[i].v) - com;
            que[i].w = lower_bound(com, com + sz, que[i].w) - com;
            assert(que[i].w > que[i].v);
            cout << bit.get(que[i].w) - bit.get(que[i].v) << endl;
        }
        else
        {
            que[i].w = lower_bound(com, com + sz, que[i].w) - com;
            bit.add(inp[que[i].v - 1], -1);
            bit.add(inp[que[i].v - 1] = que[i].w, 1);
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
