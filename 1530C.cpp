#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e5 + 10;
int n, aaa[N], bbb[N];

// int get(int i, int e, int *arr)
// {
//     if (i > n)
//     {
//         return arr[n - 1] + (i - n) * e;
//     }
//     return arr[i - 1];
// }

bool ok(int v)
{
    // k = n + v - n / 4 + v / 4
    int m = n + v, k = m - m / 4;
    assert(k <= v || k - v - 1 < n);
    int va = min(v, k) * 100 + (k > v ? aaa[k - v - 1] : 0);
    int vb = bbb[min(n, k) - 1];
    return va >= vb;
}

void mySort(int *arr)
{
    vector<int> frq(101);
    for (int i = 0; i < n; i++)
    {
        frq[arr[i]]++;
    }
    for (int i = 100, j = 0; ~i; i--)
    {
        for (; frq[i]--; j++)
        {
            arr[j] = i;
        }
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> aaa[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> bbb[i];
        }
        // sort(aaa, aaa + n, greater<int>());
        // sort(bbb, bbb + n, greater<int>());
        mySort(aaa);
        mySort(bbb);
        for (int i = 1; i < n; i++)
        {
            aaa[i] += aaa[i - 1];
            bbb[i] += bbb[i - 1];
        }
        // for (int i = 0; i <= n; i++)
        // {
        //     if (ok(i))
        //     {
        //         cout << i << endl;
        //         break;
        //     }
        // }

        int l = 0, h = n;
        while (l < h)
        {
            int m = l + (h - l) / 2;
            if (ok(m))
            {
                h = m;
            }
            else
            {
                l = m + 1;
            }
        }
        cout << h << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
