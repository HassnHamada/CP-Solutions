#include <bits/stdc++.h>
// #include <chrono>
// #include "./stdc++.h"
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;
typedef int dTyp;

extern class Node *EMPTY;
enum DIR
{
    LF,
    RT
};
class Node
{
private:
    int frq, siz, hight;
    Node *ch[2], *per;
    void link(Node *other, DIR d);
    Node *balance();
    DIR getDir(Node *other);
    void pushUp();
    Node *rotate(DIR d);

public:
    dTyp val;
    Node();
    Node(dTyp inVal);
    Node *insert(dTyp inVal);
    void print();
    int lowerBound(dTyp inVal);
    int upperBound(dTyp inVal);
    Node *index(int ind);
};
Node *EMPTY = new Node();

Node::Node()
{
    this->ch[LF] = this->ch[RT] = per = EMPTY;
    this->frq = this->siz = this->hight = 0;
}
Node::Node(dTyp inVal)
{
    this->ch[LF] = this->ch[RT] = per = EMPTY;
    this->frq = this->siz = this->hight = 1;
    this->val = inVal;
}
void Node::link(Node *other, DIR d)
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
Node *Node::balance()
{
    if (this->ch[LF]->hight > this->ch[RT]->hight + 1)
    {
        return this->rotate(RT);
    }
    if (this->ch[RT]->hight > this->ch[LF]->hight + 1)
    {
        return this->rotate(LF);
    }
    return this;
}
Node *Node::rotate(DIR d)
{
    Node *p = this->per, *q = this->ch[!d];
    this->link(q->ch[d], (DIR)(!d));
    q->link(this, d);
    p->link(q, p->getDir(this));
    return q;
}
DIR Node::getDir(Node *other)
{
    return (DIR)(this->ch[RT] == other);
}
void Node::pushUp()
{
    if (this == EMPTY)
    {
        return;
    }
    this->siz = this->frq + this->ch[LF]->siz + this->ch[RT]->siz;
    this->hight = max(this->ch[LF]->hight, this->ch[RT]->hight) + 1;
}
void Node::print()
{
    if (this == EMPTY)
    {
        return;
    }
    cout << (this->val) << " " << (this->per->val) << " " << (this->per->getDir(this)) << " " << (this->siz) << " " << (this->frq) << endl;
    this->ch[LF]->print();
    this->ch[RT]->print();
}
Node *Node::insert(dTyp inVal)
{
    if (this == EMPTY)
    {
        return new Node(inVal);
    }
    else if (inVal > this->val)
    {
        this->link(this->ch[RT]->insert(inVal), RT);
        return this->balance();
    }
    else if (inVal < this->val)
    {
        this->link(this->ch[LF]->insert(inVal), LF);
        return this->balance();
    }
    else
    {
        this->frq++;
        this->pushUp();
        return this;
    }
}
int Node::lowerBound(dTyp inVal)
{
    if (this == EMPTY)
    {
        return 0;
    }
    else if (inVal > this->val)
    {
        return this->ch[LF]->siz + this->frq + this->ch[RT]->lowerBound(inVal);
    }
    else if (inVal < this->val)
    {
        return this->ch[LF]->lowerBound(inVal);
    }
    else
    {
        return this->ch[LF]->siz;
    }
}

int Node::upperBound(dTyp inVal)
{
    return this->lowerBound(inVal + 1);
}

Node *Node::index(int ind)
{
    if (this == EMPTY)
    {
        return EMPTY;
    }
    else if (ind <= this->ch[LF]->siz)
    {
        return this->ch[LF]->index(ind);
    }
    else if (ind > this->ch[LF]->siz + this->frq)
    {
        return this->ch[RT]->index(ind - this->ch[LF]->siz - this->frq);
    }
    else
    {
        return this;
    }
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
    int n, q;
    cin >> n >> q;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        root = root->insert(v);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << (root->index(i + 1)->val) << " \n"[i == n];
    // }
    while (q--)
    {
        int o, v;
        cin >> o >> v;
        if (o == 1)
        {
            root = root->insert(root->upperBound(v) + v);
        }
        else if (o == 2)
        {
            cout << (root->lowerBound(v)) << endl;
        }
        else
        {
            Node *ret = root->index(v);
            if (ret == EMPTY)
            {
                cout << "invalid\n";
            }
            else
            {
                cout << (ret->val) << endl;
            }
        }
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}