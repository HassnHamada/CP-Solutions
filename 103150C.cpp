#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

// ezpc-zepc-zpec
const char TAR[] = "ezpczepczpec";
// char TAR[] = "ezpc";
const int N = 3, M = 4;

void run()
{
    // sort(TAR, TAR + M);
    // printf("%s\n", TAR);
    // while (next_permutation(TAR, TAR + M))
    // {
    //     printf("%s\n", TAR);
    // }

    string s;
    cin >> s;
    // for (int i = 0, k = 0; i < SZ; i++)
    // {
    //     for (int j = k; j < s.size(); j++)
    //     {
    //         if (s[j] == TAR[i])
    //         {
    //             sort(s.begin() + k, s.begin() + j + 1);
    //             k = upper_bound(s.begin() + k, s.begin() + j + 1, TAR[i]) - s.begin();
    //         }
    //     }
    // }
    bool ok = false;
    for (int i = 0; i < N; i++)
    {
        // printf("%s\n", (char *)(TAR + i));
        for (int j = 0, k = 0; j < s.size(); j++)
        {
            if (s[j] == TAR[M * i + k])
            {
                k += 1;
                if (k == M)
                {
                    ok = true;
                    break;
                }
            }
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
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
