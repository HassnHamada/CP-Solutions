#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10;
int arr[N];

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    int n, m, ans = 0;
    map<int, int> mmm;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        if (mmm.find(arr[i] - 1) == mmm.end())
        {
            ans += 1;
        }
        mmm.insert({arr[i], i});
    }
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (b < a)
        {
            swap(a, b);
        }
        pair<int, int> w = *mmm.find(arr[a]), x = *mmm.find(arr[b]),
                       y = *mmm.find(arr[a] - 1), z = *mmm.find(arr[b] - 1),
                       u = *mmm.find(arr[a] + 1), v = *mmm.find(arr[b] + 1);
        mmm[arr[a]] = b;
        mmm[arr[b]] = a;
        pair<int, int> nw = *mmm.find(arr[a]), nx = *mmm.find(arr[b]),
                       ny = *mmm.find(arr[a] - 1), nz = *mmm.find(arr[b] - 1),
                       nu = *mmm.find(arr[a] + 1), nv = *mmm.find(arr[b] + 1);
        if (y.second > w.second && ny.second < nw.second)
        {
            ans -= 1;
        }
        if (u.second > w.second && nu.second < nw.second)
        {
            ans += 1;
        }
        if (arr[b] - 1 != arr[a] && z.second < x.second && nz.second > nx.second)
        {
            ans += 1;
        }
        if (arr[b] + 1 != arr[a] && v.second < x.second && nv.second > nx.second)
        {
            ans -= 1;
        }
        swap(arr[a], arr[b]);
        printf("%d\n", ans);
    }

    // printf("%s\n", s.c_str());
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}