#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct Point
{
    ll x, y;
    bool operator<(const Point &other) const
    {
        if ((this->x) == other.x)
        {
            return (this->y) < other.y;
        }
        return (this->x) < other.x;
    }
    ll operator*(const Point &other) const
    {
        return (this->x) * other.y - (this->y) * other.x;
    }
} pnt[N];

bool oku(int i, int j, int k)
{
    Point v1 = {pnt[j].x - pnt[i].x, pnt[j].y - pnt[i].y},
          v2 = {pnt[k].x - pnt[i].x, pnt[k].y - pnt[i].y};
    return v1 * v2 <= 0;
}
bool okl(int i, int j, int k)
{
    Point v1 = {pnt[j].x - pnt[i].x, pnt[j].y - pnt[i].y},
          v2 = {pnt[k].x - pnt[i].x, pnt[k].y - pnt[i].y};
    return v1 * v2 >= 0;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &pnt[i].x, &pnt[i].y);
    }
    sort(pnt, pnt + n);
    vector<int> upper, lower;
    for (int i = 0; i < n; i++)
    {
        if (!upper.empty() && pnt[upper.back()].x == pnt[i].x)
        {
            upper.pop_back();
        }
        upper.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (!lower.empty() && pnt[lower.back()].x == pnt[i].x)
        {
            continue;
        }
        lower.push_back(i);
    }
    vector<int> upper_, lower_;
    for (int i = 0; i < (int)upper.size(); i++)
    {
        for (int j = upper_.size() - 1;
             j >= 1 && !oku(upper_[j - 1], upper_[j], upper[i]);
             j--)
        {
            upper_.pop_back();
        }
        upper_.push_back(upper[i]);
    }
    for (int i = 0; i < (int)lower.size(); i++)
    {
        for (int j = lower_.size() - 1;
             j >= 1 && !okl(lower_[j - 1], lower_[j], lower[i]);
             j--)
        {
            lower_.pop_back();
        }
        lower_.push_back(lower[i]);
    }
    vector<int> ans = upper_;
    assert(ans.back() == n - 1);
    for (int i = n - 2; i >= 0 && pnt[i].x == pnt[n - 1].x; i--)
    {
        ans.push_back(i);
    }
    assert(ans.back() == lower_.back());
    reverse(lower_.begin(), lower_.end());
    for (auto &&i : lower_)
    {
        if (i == ans.back() || i == ans.front())
        {
            continue;
        }
        ans.push_back(i);
    }
    assert(ans.back() == 0 || ans.front() == 0);
    if (pnt[0].x != pnt[n - 1].x)
    {
        for (int i = 1; i < n && pnt[i].x == pnt[0].x && i != ans.front(); i++)
        {
            ans.push_back(i);
        }
    }
    assert((int)ans.size() >= 3 && (int)ans.size() <= n);
    printf("%d\n", (int)ans.size());
    for (auto &&i : ans)
    {
        printf("%lld %lld\n", pnt[i].x, pnt[i].y);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}