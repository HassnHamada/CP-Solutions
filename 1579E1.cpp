#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

void run()
{
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        if (dq.empty() || dq.front() > v)
        {
            dq.push_front(v);
        }
        else
        {
            dq.push_back(v);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dq.front() << " \n"[i + 1 == n];
        dq.pop_front();
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
