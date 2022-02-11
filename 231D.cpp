#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

struct VEC
{
    int x, y, z;
    void set(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
} pos;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, y, z;
    cin >> x >> y >> z;
    pos.set(x, y, z);
    cin >> x >> y >> z;
    vector<int> val(6);
    for (auto &&i : val)
    {
        cin >> i;
    }
    int ans = 0;
    if (pos.y < 0)
    {
        ans += val[0];
    }
    if (pos.y > y)
    {
        ans += val[1];
    }
    if (pos.z < 0)
    {
        ans += val[2];
    }
    if (pos.z > z)
    {
        ans += val[3];
    }
    if (pos.x < 0)
    {
        ans += val[4];
    }
    if (pos.x > x)
    {
        ans += val[5];
    }
    cout << ans << endl;
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
