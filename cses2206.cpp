#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1 << 18;
int n, q, arr[N], segL[N << 1], segR[N << 1];

void build(int i = 0, int s = 0, int e = n - 1)
{
    // cout << "IN " << i << " " << s << " " << e << endl;
    if (s == e)
    {
        cin >> arr[s];
        segL[i] = arr[s] + s;
        segR[i] = arr[s] + n - 1 - s;
    }
    else
    {
        int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
        build(l, s, m);
        build(r, m + 1, e);
        segL[i] = min(segL[l], segL[r]);
        segR[i] = min(segR[l], segR[r]);
    }
    // cout << "OUT " << segL[i].first << " " << segL[i].second << endl;
}
void update(int p, int i = 0, int s = 0, int e = n - 1)
{
    if (p > e || p < s)
    {
        return;
    }
    if (s == e)
    {
        segL[i] = arr[s] + s;
        segR[i] = arr[s] + n - 1 - s;
        return;
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    update(p, l, s, m);
    update(p, r, m + 1, e);
    segL[i] = min(segL[l], segL[r]);
    segR[i] = min(segR[l], segR[r]);
}

int get(int qs, int qe, int *seg, int i = 0, int s = 0, int e = n - 1)
{
    if (qs > e || qe < s)
    {
        return INT32_MAX;
    }
    if (s >= qs && e <= qe)
    {
        return seg[i];
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    return min(get(qs, qe, seg, l, s, m), get(qs, qe, seg, r, m + 1, e));
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);

    cin >> n >> q;
    build();
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a;
        if (a & 1)
        {
            cin >> b >> c;
            // cout << a << " " << b << " " << c << endl;
            arr[--b] = c;
            update(b);
        }
        else
        {
            cin >> b;
            b--;
            cout << min(get(0, b, segR) - n + 1 + b, get(b, n - 1, segL) - b) << endl;
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}