#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e5 + 10;

struct DSU
{
    int per[N];
    void init(int n)
    {
        iota(per, per + n, 0);
    }
    int find(int a)
    {
        return per[a] == a ? a : per[a] = find(per[a]);
    }
    void merge(int a, int b)
    {
        per[find(b)] = find(a);
    }
    bool isCon(int a, int b)
    {
        return find(a) == find(b);
    }
} dsu;

struct Vertices
{
    int x, y, z;
    bool operator<(const Vertices &other) const
    {
        if (this->x == other.x)
        {
            if (this->y == other.y)
            {
                return this->z < other.z;
            }
            return this->y < other.y;
        }
        return this->x < other.x;
    }
} arr[3 * N];

map<Vertices, map<Vertices, int>> mmm;

void run()
{
    int n;
    cin >> n;
    dsu.init(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[3 * i + j].x >> arr[3 * i + j].y >> arr[3 * i + j].z;
        }
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (j == k)
                {
                    continue;
                }
                if (mmm.find(arr[3 * i + j]) != mmm.end() && mmm[arr[3 * i + j]].find(arr[3 * i + k]) != mmm[arr[3 * i + j]].end())
                {
                    dsu.merge(mmm[arr[3 * i + j]][arr[3 * i + k]], i);
                }
                mmm[arr[3 * i + j]][arr[3 * i + k]] = i;
            }
        }
    }
    bool ok = true;
    for (int i = 1; i < n; i++)
    {
        ok &= dsu.isCon(0, i);
    }
    cout << (ok ? "Yes" : "No") << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen("triangles.in", "r", stdin);
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}