#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> frq(26);
    string s;
    s.reserve(2 * k);
    cin >> s;
    for (auto &&i : s)
    {
        frq[i - 'a']++;
    }
    char c = s[0], t = 0;
    for (int i = c - 'a' + 1; i < 26; i++)
    {
        t += frq[i];
    }
    while (t)
    {
        char l = s[s.size() - 1];
        if (l > c)
        {
            t -= 1;
        }
        s.pop_back();
    }
    while (s.size() > 1 && s[s.size() - 1] == c)
    {
        s.pop_back();
    }

    while (s.size() < k)
    {
        s += s;
    }
    while (s.size() > k)
    {
        s.pop_back();
    }
    printf("%s\n", s.c_str());
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
