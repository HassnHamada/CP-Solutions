#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

// const int N = 2e5;
// int arr[N];

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        map<int, int> mmm;
        scanf("%d", &n);
        for (int i = 0, v; i < n; i++)
        {
            scanf("%d", &v);
            if (mmm.find(v) == mmm.end())
            {
                mmm.insert({v, 0});
            }
            mmm[v] += 1;
        }
        int c = 0, s = INT32_MAX;
        for (auto &&i : mmm)
        {
            // cout << i.first << " " << i.second << endl;
            if (i.second > c || (i.second == c && i.first < s))
            {
                c = i.second;
                s = i.first;
            }
        }
        // cout << s << endl;
        for (auto i = mmm.find(s); i != mmm.end();)
        {
            printf("%d ", i->first);
            i->second -= 1;
            auto j = i;
            i++;
            if (j->second == 0)
            {
                mmm.erase(j);
            }
        }

        while (!mmm.empty())
        {
            for (auto i = mmm.begin(); i != mmm.end();)
            {
                if (i->first == s && i->second == 1)
                {
                    i++;
                    continue;
                }
                printf("%d ", i->first);
                i->second -= 1;
                auto j = i;
                i++;
                if (j->second == 0)
                {
                    mmm.erase(j);
                }
            }
            if (mmm.size() == 1)
            {
                assert(mmm.begin()->first == s);
                for (int i = 0; i < mmm.begin()->second; i++)
                {
                    printf("%d ", s);
                }
                break;
            }
            // auto i = mmm.begin();
            // if (i->second == 1 && mmm.size())
            // {
            // }
        }
        printf("\n");
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28
// L L L W L W L L L W  L  W  L  W  L  W  L  W  L  W  L  W  L  W  L  W  L  