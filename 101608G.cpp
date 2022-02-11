#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e5 + 10;
int arr[N];

struct INT
{
    vector<int> vec{vector<int>(32, 0)};
    void operator+=(int other)
    {
        for (int i = 0; i < 32; i++)
        {
            vec[i] += (other >> i) & 1;
        }
    }

    void operator-=(int other)
    {
        for (int i = 0; i < 32; i++)
        {
            vec[i] -= (other >> i) & 1;
        }
    }
    operator int() const
    {
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            ret |= ((this->vec[i] ? 1 : 0) << i);
        }
        return ret;
    }
    // void prn()
    // {
    //     for (int i = 0; i < 32; i++)
    //     {
    //         cout << (this->vec[i]) << " \n"[i == 31];
    //     }
    // }
};

void run()
{
    int n, v;
    cin >> n >> v;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 0, r = 0, ans = 0;
    INT val;
    while (r < n)
    {
        val += arr[r++];
        while ((int)(val) > v)
        {
            val -= arr[l++];
        }
        ans = max(ans, r - l);
        assert(l <= r);
        // val.prn();
        // cout << (int)(val) << endl;
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen("wifi.in", "r", stdin);
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
