#include <bits/stdc++.h>
// #include <chrono>
// #include "./stdc++.h"
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;
typedef int treapTyp;
mt19937 eng{std::random_device{}()};
uniform_int_distribution<int> uid(0, INT32_MAX);

extern class Node *EMPTY;

enum Dir
{
    LF,
    RT
};

class Node
{

public:
    treapTyp val;
    int pri, sz;
    Node *ch[2], *per;
    bool rev;
    Node();
    Node(treapTyp nodeVal);
    ~Node();
    // Node *rotate(Dir d);
    void link(Node *other, Dir d);
    void pushUp();
    void pushDown();
    Dir getDir(Node *other);
    // Node *insert(treapTyp nodeVal);
    // Node *balance();
    void print(Node *nodePer);
    pair<Node *, Node *> split(int leftSize);
    Node *merge(Node *other);
    void reverse();
    Node *index(int i);
    // void pushDownFromRoot();
};

Node::Node()
{
    sz = 0;
    ch[0] = ch[1] = per = this;
    pri = INT32_MIN;
    rev = false;
}

Node::Node(treapTyp nodeVal)
{
    val = nodeVal;
    sz = 1;
    ch[0] = ch[1] = per = EMPTY;
    pri = rand();
    rev = false;
}

Node::~Node(){};

// Node *Node::rotate(Dir d)
// {
//     Node *p = this->per, *q = this->ch[d ^ 1];
//     this->link(q->ch[d], (Dir)(d ^ 1));
//     q->link(this, d);
//     p->link(q, p->getDir(this));
//     return q;
// }

void Node::link(Node *other, Dir d)
{
    if (other != EMPTY)
    {
        other->per = this;
    }
    if (this != EMPTY)
    {
        this->ch[d] = other;
        this->pushUp();
    }
}

void Node::pushUp()
{
    this->sz = this->ch[0]->sz + this->ch[1]->sz + 1;
}

Dir Node::getDir(Node *other)
{
    return (Dir)(this->ch[RT] == other);
}

// Node *Node::insert(treapTyp nodeVal)
// {
//     if (this == EMPTY)
//     {
//         return new Node(nodeVal);
//     }
//     Dir d = this->val > nodeVal ? LF : RT;
//     this->link(this->ch[d]->insert(nodeVal), d);
//     return this->balance();
// }

// Node *Node::balance()
// {
//     Node *ret = this;
//     if (ret->pri < ret->ch[LF]->pri)
//     {
//         ret = ret->rotate(RT);
//     }
//     if (ret->pri < ret->ch[RT]->pri)
//     {
//         ret = ret->rotate(LF);
//     }
//     ret->pushUp();
//     return ret;
// }

void Node::print(Node *nodePer = EMPTY)
{
    if (this == EMPTY)
    {
        return;
    }
    cout << "(" << (this->val) << ", " << (nodePer->val) << ", " << (nodePer->getDir(this)) << ", " << (this->sz) << ", " << (this->per->val) << ", " << (this->pri) << ")\n";
    this->ch[LF]->print(this);
    this->ch[RT]->print(this);
}

void Node::pushDown()
{
    if (this == EMPTY || !this->rev)
    {
        return;
    }
    this->ch[LF]->reverse();
    this->ch[RT]->reverse();
    this->rev = false;
}

pair<Node *, Node *> Node::split(int leftSize)
{
    // cout << (this->val) << " " << leftSize << endl;
    if (this == EMPTY)
    {
        return {EMPTY, EMPTY};
    }
    this->pushDown();
    if (this->ch[LF]->sz < leftSize)
    {
        pair<Node *, Node *> ret = this->ch[RT]->split(leftSize - this->ch[LF]->sz - 1);
        this->link(ret.first, RT);
        ret.second->per = EMPTY;
        // return {this->balance(), ret.second->balance()};
        return {this, ret.second};
    }
    else
    {
        pair<Node *, Node *> ret = this->ch[LF]->split(leftSize);
        this->link(ret.second, LF);
        ret.first->per = EMPTY;
        // return {ret.first->balance(), this->balance()};
        return {ret.first, this};
    }
}
Node *Node::merge(Node *other)
{
    if (this == EMPTY)
    {
        return other;
    }
    if (other == EMPTY)
    {
        return this;
    }
    this->pushDown();
    other->pushDown();
    if (this->pri > other->pri)
    {
        this->link(this->ch[RT]->merge(other), RT);
        return this;
    }
    else
    {
        other->link(this->merge(other->ch[LF]), LF);
        return other;
    }
}

void Node::reverse()
{
    if (this == EMPTY)
    {
        return;
    }
    swap(ch[0], ch[1]);
    rev ^= true;
}
Node *Node::index(int i)
{
    if (this == EMPTY)
    {
        return EMPTY;
    }
    this->pushDown();
    if (this->ch[LF]->sz > i)
    {
        return this->ch[LF]->index(i);
    }
    else if (this->ch[LF]->sz == i)
    {
        return this;
    }
    else
    {
        return this->ch[RT]->index(i - this->ch[LF]->sz - 1);
    }
}

// void Node::pushDownFromRoot()
// {
//     if (this == EMPTY)
//     {
//         return;
//     }
//     this->per->pushDownFromRoot();
//     this->pushDown();
// }

Node *EMPTY = new Node();

void temp(Node *root, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << (root->index(i)->val) << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Node *root = EMPTY;
    int n, q, m;
    cin >> n >> q >> m;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        root = root->merge(new Node(v));
        // temp(root, i + 1);
        // root->print();
    }
    // root->print();
    // temp(root, n);
    for (int i = 0, o, l, r; i < q; i++)
    {
        cin >> o >> l >> r;
        if (o & 1)
        {
            pair<Node *, Node *> aaa = root->split(l - 1);
            pair<Node *, Node *> bbb = aaa.second->split(r - l);
            pair<Node *, Node *> ccc = bbb.second->split(1);
            root = aaa.first->merge(ccc.first);
            root = root->merge(bbb.first);
            root = root->merge(ccc.second);
            // temp(aaa.first, l - 1);
            // temp(aaa.second, n - l + 1);
            // root->print();
            // bbb.first->print();
            // temp(ccc.second, n - r);
        }
        else
        {
            pair<Node *, Node *> aaa = root->split(l - 1);
            pair<Node *, Node *> bbb = aaa.second->split(r - l + 1);
            // temp(bbb.first, r - l + 1);
            // temp(bbb.second, n - (r - l + 1) - (l - 1));
            // cout << (aaa.first == EMPTY) << endl;
            bbb.first->reverse();
            root = aaa.first->merge(bbb.first);
            root = root->merge(bbb.second);
        }
        // temp(root, n);
    }
    for (int i = 0, v; i < m; i++)
    {
        cin >> v;
        cout << (root->index(v - 1)->val) << " \n"[i + 1 == m];
    }

    // root->print();
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}