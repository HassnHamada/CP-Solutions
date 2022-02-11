#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 12;
const pair<int, int> targets[] = {{3, 3}, {3, 10}, {10, 3}, {10, 10}},
                     blocks[] = {{6, 6}, {6, 7}, {7, 6}, {7, 7}, {9, 2}, {9, 3}, {10, 2}, {9, 10}, {9, 11}, {10, 11}};
int dis[N + 1][N + 1];

bool inBlocks(pair<int, int> pos)
{
    return any_of(blocks, blocks + 10, [&pos](pair<int, int> block)
                  { return block == pos; });
}

bool inTargets(pair<int, int> pos)
{
    return any_of(targets, targets + 4, [&pos](pair<int, int> target)
                  { return target == pos; });
}
bool valid(pair<int, int> pos)
{
    return pos.first >= 1 && pos.first <= N && pos.second >= 1 && pos.second <= N && !inBlocks(pos);
}

void posMoves(pair<int, int> pos, vector<pair<int, int>> &in)
{
    if (pos.first != 1 && !inBlocks({pos.first - 1, pos.second}))
    {
        in.push_back({pos.first - 1, pos.second});
    }
    if (pos.first != N && !inBlocks({pos.first + 1, pos.second}))
    {
        in.push_back({pos.first + 1, pos.second});
    }
    if (pos.second != 1 && !inBlocks({pos.first, pos.second - 1}))
    {
        in.push_back({pos.first, pos.second - 1});
    }
    if (pos.second != N && !inBlocks({pos.first, pos.second + 1}))
    {
        in.push_back({pos.first, pos.second + 1});
    }
}

int minDis(pair<int, int> pos)
{
    return dis[pos.first][pos.second];
}

char getDir(int i)
{
    if (i == 0)
    {
        return 'D';
    }
    else if (i == 1)
    {
        return 'U';
    }
    else if (i == 2)
    {
        return 'R';
    }
    return 'L';
}

pair<int, int> getNew(pair<int, int> &pos, int dir)
{
    pair<int, int> newPos = {pos.first + (dir == 0 ? 1 : (dir == 1 ? -1 : 0)), pos.second + (dir == 2 ? 1 : (dir == 3 ? -1 : 0))};
    return valid(newPos) ? newPos : pos;
}

int cost(pair<int, int> &pos1, pair<int, int> &pos2, pair<int, int> &pos3, pair<int, int> &pos4, int dir)
{
    pair<int, int> newPos1 = getNew(pos1, dir),
                   newPos2 = getNew(pos2, dir),
                   newPos3 = getNew(pos3, dir),
                   newPos4 = getNew(pos4, dir);
    return minDis(newPos1) + minDis(newPos2) + minDis(newPos3) + minDis(newPos4);
}

int comp(pair<int, int> pos1, pair<int, int> pos2, pair<int, int> pos3, pair<int, int> pos4, int dir1, int dir2)
{
    if (cost(pos1, pos2, pos3, pos4, dir1) <= cost(pos1, pos2, pos3, pos4, dir1))
    {
        return true;
    }
    return false;
}

bool greedy(pair<int, int> pos1, pair<int, int> pos2, pair<int, int> pos3, pair<int, int> pos4, string &ans)
{
    cout << pos1.first << " " << pos1.second << " "
         << pos2.first << " " << pos2.second << " "
         << pos3.first << " " << pos3.second << " "
         << pos4.first << " " << pos4.second << endl;
    if (inTargets(pos1) && inTargets(pos2) && inTargets(pos3) && inTargets(pos4))
    {
        printf("%d\n", ans.size());
        return true;
    }
    vector<int> moves = {0, 1, 2, 3};
    sort(moves.begin(), moves.end(), [&pos1, &pos2, &pos3, &pos4](int i, int j)
         { return comp(pos1, pos2, pos3, pos4, i, j); });
    for (auto &&i : moves)
    {
        ans.push_back(getDir(i));
        if (greedy(getNew(pos1, i), getNew(pos2, i), getNew(pos3, i), getNew(pos4, i), ans))
        {
            return true;
        }
        ans.pop_back();
    }
    return false;
}

void bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < 4; i++)
    {
        q.push(targets[i]);
    }
    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();
        vector<pair<int, int>> moves;
        posMoves(pos, moves);
        for (auto &&i : moves)
        {
            if (dis[i.first][i.second] || inTargets(i))
            {
                continue;
            }
            dis[i.first][i.second] = dis[pos.first][pos.second] + 1;
            q.push(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);

    memset(dis, 0x11, sizeof(dis));
    // cout << dis[0][0] << endl;
    for (int i = 0; i < 4; i++)
    {
        dis[targets[i].first][targets[i].second] = 0;
    }
    bfs();
    int l;
    cin >> l;
    while (l--)
    {
        int r1, c1, r2, c2, r3, c3, r4, c4;
        cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3 >> r4 >> c4;
        string ans;
        greedy({r1, c1}, {r2, c2}, {r3, c3}, {r4, c4}, ans);
        printf("%s\n", ans.c_str());
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}