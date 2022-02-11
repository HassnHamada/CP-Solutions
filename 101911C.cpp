#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10;
int arr[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return 1ll * a * b / gcd(a, b);
}

bool ok(int n)
{
    bool ret = true;
    int mx = *max_element(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        ret &= (mx % arr[i] == 0) && (__builtin_popcount(mx / arr[i]) == 1);
    }
    return ret;
}

void run()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout << gcd(1, 4) << endl;
    if (ok(n))
    {
        int mn = *min_element(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            arr[i] /= mn;
        }
        int ans = 0, l;
        vector<int> frq(100, 0);
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < n; j++)
            {
                assert(__builtin_popcount(arr[j]) == 1);
                // cout << (arr[j] >> i) << endl;
                frq[i] += ((arr[j] >> i) == 1);
            }
            if (frq[i])
            {
                l = i;
            }
        }
        // cout << l << endl;
        for (int i = 0; i < l; i++)
        {
            // cout << frq[i] << " " << frq[i + 1] << endl;
            frq[i + 1] += (frq[i] + 1) / 2;
            // cout << frq[i] << " " << frq[i + 1] << endl;
            ans += frq[i] & 1;
            // cout << ans << endl;
        }
        for (; frq[l] != 1; l++)
        {
            frq[l + 1] += (frq[l] + 1) / 2;
            ans += frq[l] & 1;
        }
        cout << ans << endl;
    }
    else
    {
        cout << "-1\n";
    }
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
    int test = 1;
    // cin >> t;
    while (test--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}