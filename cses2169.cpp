#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10;
int ans[N], srt[N << 1];
struct Node
{
    int left, right, index;
    bool operator<(Node &other)
    {
        return this->left == other.left ? this->right > other.right : this->left < other.left;
    }
    // bool operator>(Node &other)
    // {
    //     return this->left == other.left ? this->right > other.right : this->left > other.left;
    // }
} arr[N];

std::ostream &operator<<(std::ostream &os, Node node)
{
    return os << node.left << " " << node.right;
}

struct BIT
{
    int tree[N << 1], sz = 0;
    void init()
    {
        memset(tree, 0, sizeof tree);
        sz = 0;
    }
    void add(int pos, int val = 1)
    {
        for (++pos; pos <= 2 * N; pos += (pos & (-pos)))
            tree[pos - 1] += val;
        sz += 1;
    }
    int get(int pos)
    {
        int ret = 0;
        for (++pos; pos; pos -= (pos & (-pos)))
            ret += tree[pos - 1];
        return ret;
    }
} bit;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &arr[i].left, &arr[i].right);
        arr[i].index = i;
        srt[2 * i] = arr[i].left;
        srt[2 * i + 1] = arr[i].right;
    }
    sort(srt, srt + 2 * n);
    int sz = unique(srt, srt + 2 * n) - srt;
    for (int i = 0; i < n; i++)
    {
        arr[i].left = lower_bound(srt, srt + sz, arr[i].left) - srt;
        arr[i].right = lower_bound(srt, srt + sz, arr[i].right) - srt;
    }
    sort(arr, arr + n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    bit.init();
    for (int i = n - 1; ~i; i--)
    {
        ans[arr[i].index] = bit.get(arr[i].right);
        bit.add(arr[i].right);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }
    bit.init();
    for (int i = 0; i < n; i++)
    {
        ans[arr[i].index] = bit.sz - bit.get(arr[i].right - 1);
        bit.add(arr[i].right);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}