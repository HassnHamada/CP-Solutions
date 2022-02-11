#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e6;
int A[N], C[N], G[N], T[N], ai, ci, gi, ti, sz;

void dfs(int s, string &ans)
{
    int *a = lower_bound(A, A + ai, s),
        *c = lower_bound(C, C + ci, s),
        *g = lower_bound(G, G + gi, s),
        *t = lower_bound(T, T + ti, s);
    if (a == A + ai)
    {
        ans.push_back('A');
        return;
    }
    if (c == C + ci)
    {
        ans.push_back('C');
        return;
    }
    if (g == G + gi)
    {
        ans.push_back('G');
        return;
    }
    if (t == T + ti)
    {
        ans.push_back('T');
        return;
    }
    int m = max({*a, *c, *g, *t});
    if (m == *a)
    {
        ans.push_back('A');
    }
    if (m == *c)
    {
        ans.push_back('C');
    }
    if (m == *g)
    {
        ans.push_back('G');
    }
    if (m == *t)
    {
        ans.push_back('T');
    }
    dfs(m + 1, ans);
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);

    string s;
    cin >> s;
    sz = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case 'A':
            A[ai++] = i;
            break;
        case 'C':
            C[ci++] = i;
            break;
        case 'G':
            G[gi++] = i;
            break;
        case 'T':
            T[ti++] = i;
            break;
        default:
            assert(false);
            break;
        }
    }
    string ans;
    dfs(0, ans);
    cout << ans << endl;
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}