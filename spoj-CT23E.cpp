#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 710;
int ind[N];
vector<int> grf[N];

void insert(int a, int b)
{
    assert(ind[a] <= grf[a].size());
    if (ind[a] == grf[a].size())
    {
        grf[a].resize(2 * max((int)(grf[a].size()), 1));
    }
    grf[a][ind[a]++] = b;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1, a, b; i < n; i++)
    {
        cin >> a >> b;
        insert(a, b);
        insert(b, a);
    }

    cout << ans << endl;
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
