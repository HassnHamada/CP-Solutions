#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 5e5 + 10;
set<pair<int, int>> sss;
int n;
bitset<N> arr;
// char str[N];

void getStable()
{
    int i = 1, s = 0;
    while (true)
    {
        while (i < n && arr[i] == arr[i - 1])
        {
            i += 1;
        }
        sss.insert({s, i});
        if (i == n)
        {
            break;
        }
        while (i < n && arr[i] != arr[i - 1])
        {
            i += 1;
        }
        s = i - 1;
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        arr[i] = v;
        // cout << arr[i] << endl;
    }
    getStable();
    // for (auto &&i : sss)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    // cout << " das" << sss.size();
    int ans = 0;
    for (auto i = sss.begin();;)
    {
        auto j = i;
        i++;
        if (i == sss.end())
        {
            break;
        }
        // cout << (j->first) << " " << (j->second) << endl;
        // cout << (i->first) << " " << (i->second) << endl;
        ans = max(ans, (i->first - j->second + 1) / 2);
        for (int k = 0; k < (i->first - j->second + 1) / 2; k += 2)
        {
            arr[j->second + k].flip();
            if (j->second + k < i->first - k - 1)
            {
                arr[i->first - k - 1].flip();
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", (int)(arr[i]), i - 1 == n ? '\n' : ' ');
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}