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
    bool rev;

    Node() : ch({this, this}), par(this), frq(0), sz(0), pri(INT_MIN), rev(false){};

    Node(int val) : ch({EMPTY, EMPTY}), par(EMPTY), frq(1), sz(1), pri(rand()), val(val), rev(false){};

    void reverse()
    {
        if (this == EMPTY)
        {
            return;
        }
        swap(ch[0], ch[1]);
        rev ^= 1;
    }
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

void push_down(Node *&cur)
{
    if (cur == EMPTY || !cur->rev)
    {
        return;
    }
    cur->ch[0]->reverse();
    cur->ch[1]->reverse();
    cur->rev = 0;
}

void pushDownFromRoot(Node *cur)
{
    if (cur == EMPTY)
        return;
    pushDownFromRoot(cur->par);
    push_down(cur);
}

int getDir(Node *pr, Node *child)
{
    return pr->ch[0] == child ? 0 : 1;
}

void print(Node *cur, int p = -1)
{
    if (cur == EMPTY)
    {
        return;
    }
    cout << "(" << p << ", " << (cur->val) << ", " << (cur->par == EMPTY ? -1 : getDir(cur->par, cur)) << ")\n";
    print(cur->ch[0], cur->val);
    print(cur->ch[1], cur->val);
    cout << (p == -1 ? "\n" : "");
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

Node *insert(Node *&cur, int val)
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
        // cout << "1 " << (cur->val) << endl;
        // insert(cur->ch[0], val);
        link(cur, insert(cur->ch[0], val), 0);
    }
    else
    {
        // cout << "2 " << (cur->val) << endl;
        link(cur, insert(cur->ch[1], val), 1);
    }
    push_up(cur);
    // cout << "HI\n";
    // print(cur);
    balance(cur);
    return cur;
}

Node *getByIdx(Node *root, int idx)
{
    if (root == EMPTY)
        return EMPTY;
    if (root->ch[0]->sz > idx)
        return getByIdx(root->ch[0], idx);
    int tmp = root->ch[0]->sz + root->frq;
    if (tmp <= idx)
        return getByIdx(root->ch[1], idx - tmp);
    return root;
}

Node *bubble(Node *c)
{
    while (c->par != EMPTY)
    {
        int d = getDir(c->par, c);
        Node *p = c->par, *pp = c->par->par, *q = c->ch[!d];
        link(p, q, d);
        link(c, p, 1 ^ d);
        link(pp, c, getDir(pp, p));
    }
    return c;
}

void split(Node *cur, int sz, Node *&les, Node *&grt)
{
    if (cur == EMPTY)
    {
        les = grt = EMPTY;
        return;
    }
    push_down(cur);
    Node *tmp;
    if (sz <= cur->ch[0]->sz)
    {
        grt = cur;
        split(cur->ch[0], sz, les, tmp);
        link(cur, tmp, 0);
    }
    else
    {
        les = cur;
        split(cur->ch[1], sz - cur->ch[0]->sz - 1, tmp, grt);
        link(cur, tmp, 1);
    }
    // print(cur);
    // if (sz == 0)
    // {
    //     Node *tar = getByIdx(cur, cur->sz - 1);
    //     pushDownFromRoot(tar);
    //     grt = cur;
    //     les = EMPTY;
    // }
    // else
    // {
    //     Node *tar = getByIdx(cur, sz - 1);
    //     pushDownFromRoot(tar);
    //     cur = bubble(tar);
    //     grt = cur->ch[1];
    //     grt->par = EMPTY;
    //     cur->ch[1] = EMPTY;
    //     push_up(cur);
    //     les = cur;
    // }
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

Node *merge(Node *les, Node *grt)
{
    // print(les);
    // print(grt);
    if (les == EMPTY)
        return grt;
    if (grt == EMPTY)
        return les;
    push_down(grt);
    push_down(les);
    Node *cur;
    if (les->pri > grt->pri)
    {
        cur = les;
        link(cur, merge(cur->ch[1], grt), 1);
    }
    else
    {
        cur = grt;
        link(cur, merge(les, cur->ch[0]), 0);
    }
    return cur;
}
int getIdx(Node *cur)
{
    pushDownFromRoot(cur);
    int ret = cur->ch[0]->sz;
    while (cur->par != EMPTY)
    {
        auto p = cur->par;
        if (getDir(p, cur) == 1)
            ret += p->ch[0]->sz + 1;
        cur = p;
    }
    return ret;
}

void reverse(Node *&cur, int st, int en)
{
    // cout << st << " " << en << endl;
    Node *bef, *aft, *btwn;
    split(cur, en + 1, cur, aft);
    // cout << "cur\n";
    // print(cur);
    // cout << "aft\n";
    // print(aft);
    split(cur, st, bef, btwn);
    // cout << "bef\n";
    // print(bef);
    // cout << "btwn\n";
    // print(btwn);
    btwn->reverse();
    cur = merge(btwn, aft);
    cur = merge(bef, cur);
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
    int n;
    Node *root = EMPTY;
    while (cin >> n, n)
    {
        root = EMPTY;
        vector<Node *> V;
        int x;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            V.emplace_back(new Node(x));
            root = merge(root, V.back());
        }
        stable_sort(V.begin(), V.end(), [](Node *a, Node *b)
                    { return a->val < b->val; });
        int i = 0;
        for (Node *&nod : V)
        {
            int idx = getIdx(nod);
            cout << idx + 1 << " \n"[nod == V.back()];
            reverse(root, i++, idx);
        }
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
