#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 50;
int arr[N], srt[N], n;

int getLoc(int s, int t)
{
    for (int i = s; i < n; i++)
    {
        if (arr[i] == t)
        {
            return i;
        }
    }
    assert(false);
    // return -1;
}

void rotate(int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        swap(arr[l], arr[i]);
    }
}

void run()
{
    // int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        srt[i] = arr[i];
    }
    sort(srt, srt + n);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (srt[i] == arr[i])
        {
            continue;
        }
        int l = i, r = getLoc(i, srt[i]);
        // cout << l << " " << r << endl;
        ans.push_back({l, r});
        rotate(l, r);
    }
    for (int i = 0; i < n; i++)
    {
        // cout << srt[i] << " " << arr[i] << endl;
        assert(srt[i] == arr[i]);
    }
    cout << ans.size() << endl;
    for (auto &&i : ans)
    {
        cout << i.first + 1 << " " << i.second + 1 << " " << i.second - i.first << endl;
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
