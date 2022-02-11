#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e6 + 10;
int vis[N], vid;
// int arr[N], srt[N << 1];

void run()
{
    vid++;
    int n, d;
    cin >> n >> d;
    vector<int> vec;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        if (!v)
        {
            vec.push_back(i);
            vis[i] = vid;
        }
    }
    int ans = -1;
    while (vec.size())
    {
        // cout << "sad\n";
        vector<int> tem;
        for (auto &&i : vec)
        {
            int j = (i + d) % n;
            if (vis[j] == vid)
            {
                continue;
            }
            tem.push_back(j);
            vis[j] = vid;
        }
        // cout << tem.size() << endl;
        swap(vec, tem);
        ans++;
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        ok &= (vis[i] == vid);
    }
    cout << (ok ? ans : -1) << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
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
