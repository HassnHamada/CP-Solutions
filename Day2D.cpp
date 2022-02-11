#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

int dir, fil;
map<string, set<string>> hyr;

void prn(string &str, string sft)
{
    cout << str << endl;
    vector<string> vec;
    for (auto &&i : hyr[str])
    {
        vec.push_back(i);
    }
    for (auto &&i : vec)
    {
        if (i == vec.back())
        {
            cout << sft << "|__ ";
            prn(i, sft + "   ");
        }
        else
        {
            cout << sft << "|-- ";
            prn(i, sft + "|   ");
        }
    }
    (hyr[str].empty() ? fil : dir) += 1;
}

void run()
{
    int n;
    string seed;
    cin >> seed >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        if (hyr.find(a) == hyr.end())
        {
            hyr.emplace(a, set<string>());
        }
        hyr[a].insert(b);
    }
    prn(seed, "");
    cout << "\n"
         << dir << " directories, " << fil << " files\n";
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
