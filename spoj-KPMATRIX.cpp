#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;
mt19937 eng{std::random_device{}()};
uniform_int_distribution<int> uid(0, (int)(2e9));

const int N = 260;
ll mat[N][N];

extern struct Node *EMPTY;
struct Node
{
    int val, pri, sz, frq;
    Node *ch[2], *par;

    Node() : ch({this, this}), par(this), frq(0), sz(0), pri(INT_MIN){};

    Node(int val) : ch({EMPTY, EMPTY}), par(EMPTY), frq(1), sz(1), pri(rand()), val(val){};
};
Node *EMPTY = new Node();

void push_up(Node *cur)
{
    cur->sz = cur->frq + cur->ch[0]->sz + cur->ch[1]->sz;
}

void link(Node *pr, Node *child, int dir)
{
    if (child != EMPTY)
    {
        child->par = pr;
    }
    if (pr != EMPTY)
    {
        pr->ch[dir] = child;
        push_up(pr);
    }
}

int getDir(Node *pr, Node *child)
{
    return pr->ch[0] == child ? 0 : 1;
}

void rotate(Node *&p, int d)
{
    Node *pp = p->par, *q = p->ch[!d];
    link(p, q->ch[d], d ^ 1);
    link(q, p, d);
    link(pp, q, getDir(pp, p));
    p = q;
}

void balance(Node *&cur)
{
    if (cur->ch[1]->pri > cur->pri)
    {
        rotate(cur, 0);
    }
    else if (cur->ch[0]->pri > cur->pri)
    {
        rotate(cur, 1);
    }
}

void insert(Node *&cur, int val)
{
    if (cur == EMPTY)
        cur = new Node(val);
    else if (cur->val == val)
    {
        cur->frq++;
        // cur->sz++;
    }
    else if (val < cur->val)
    {
        insert(cur->ch[0], val);
    }
    else
    {
        insert(cur->ch[1], val);
    }
    push_up(cur);
    balance(cur);
}

Node *remv_node(Node *cur)
{
    for (int d = 0; d < 2; ++d)
    {
        if (cur->ch[d] == EMPTY)
        {
            auto toDel = cur;
            link(cur->par, cur->ch[!d], getDir(cur->par, cur));
            cur = cur->ch[!d];
            delete toDel;
            return cur;
        }
    }
    if (cur->ch[0]->pri > cur->ch[1]->pri)
    {
        rotate(cur, 1);
        cur->ch[1] = remv_node(cur->ch[1]);
    }
    else
    {
        rotate(cur, 0);
        cur->ch[0] = remv_node(cur->ch[0]);
    }
    return cur;
}

void del(Node *&root, int val)
{
    if (root == EMPTY)
        return;
    if (root->val == val)
    {
        if (!--root->frq)
        {
            root = remv_node(root);
        }
    }
    else if (root->val > val)
    {
        del(root->ch[0], val);
    }
    else
    {
        del(root->ch[1], val);
    }
    push_up(root);
}

int getByIdx(Node *root, int idx)
{
    if (root == EMPTY)
        return INT_MIN;
    if (root->ch[0]->sz > idx)
        return getByIdx(root->ch[0], idx);
    int tmp = root->ch[0]->sz + root->frq;
    if (tmp <= idx)
        return getByIdx(root->ch[1], idx - tmp);
    return root->val;
}

int lower_bound(Node *root, int val)
{
    if (root == EMPTY)
        return 0;
    if (val == root->val)
        return root->ch[0]->sz;
    if (val < root->val)
        return lower_bound(root->ch[0], val);
    int tmp = root->ch[0]->sz + root->frq;
    return tmp + lower_bound(root->ch[1], val);
}

int upper_bound(Node *root, int val)
{
    return lower_bound(root, val + 1);
}

int count(Node *root, int val)
{
    if (root == EMPTY)
        return 0;
    if (root->val == val)
        return root->frq;
    if (val < root->val)
        return count(root->ch[0], val);
    return count(root->ch[1], val);
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
            mat[i][j] += mat[i][j - 1];
        }
    }
    int a, b;
    cin >> a >> b;
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            Node *root = new Node(0);
            ll sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += mat[k][j] - mat[k][i];
                ans += upper_bound(root, sum - a) - lower_bound(root, sum - b);
                insert(root, sum);
            }
        }
    }
    cout << ans << endl;
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
