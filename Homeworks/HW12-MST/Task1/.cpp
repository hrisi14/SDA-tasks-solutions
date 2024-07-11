#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

int parent[MAX];
int depth[MAX];

struct Edge
{
    int to;
    int from;
    int weight;

    Edge(int newFrom, int newTo, int newWeight) : from(newFrom), to(newTo), weight(newWeight)
    {}
    bool operator<(const Edge& other)
    {
        return this->weight < other.weight;
    }
};

void initialize(int N)   //in case I ndeed Kruskal's algorithm
{
    for (int i = 0; i < N; i++)
    {
        depth[i] = 1;
        parent[i] = i;
    }
}

int Find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y)
{
    int root1 = Find(x);
    int root2 = Find(y);

    if (root1 == root2)
    {
        return false;
    }
    if (depth[root2] > depth[root1])
    {
        swap(root1, root2);
    }
    else if (depth[root1] == depth[root2])
    {
        depth[root1]++;
    }
    parent[root2] = root1;
    return true;
}

int main()
{
    int N, M;
    cin >> N >> M;
    initialize(N);
    vector<Edge> edges;  
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        edges.push_back({ from, to, 1 });
        Union(from, to);
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1)
        {
            if (Find(a) == Find(b))
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        else if (type == 2)
        {
            Union(a,b);
            
        }
    }
}
