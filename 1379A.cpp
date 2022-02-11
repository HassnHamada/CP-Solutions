#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const string TAR = "abacaba";

int count(string &str)
{
    int ret = 0;
    for (int i = 0; i <= str.size() - TAR.size(); i++)
    {
        // ret += mismatch(TAR.begin(), TAR.end(), str.substr(i).begin()).first == TAR.end();
        ret += str.substr(i, TAR.size()) == TAR;
    }
    return ret;
}

void ans()
{
    string str;
    cin >> str;
    for (int i = 0; i <= str.size() - TAR.size(); i++)
    {
        string ss = str;
        bool ok = true;
        for (int j = 0; j < TAR.size(); j++)
        {
            if (ss[i + j] == '?' || ss[i + j] == TAR[j])
            {
                ss[i + j] = TAR[j];
                continue;
            }
            ok = false;
            break;
        }
        if (ok && count(ss) == 1)
        {

            cout << "Yes\n";
            for (int j = 0; j < ss.size(); j++)
            {
                cout << (ss[j] == '?' ? 'z' : ss[j]);
            }
            cout << endl;
            return;
        }
    }
    cout << "No\n";
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ans();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
