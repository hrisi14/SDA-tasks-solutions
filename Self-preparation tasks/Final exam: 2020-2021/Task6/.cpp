#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Task's goal: building a MaxST

const int MAX = 10^6;
struct Edge
{
    int from;
    int to;
    int weight;
    
    bool operator<(const Edge& other) const
    {
        return this->weight<other.weight;
    }
};

vector<long long> parents;
vector<long long> depths;
long long ccNumber;

void fillParents(int V)
{
    parents.resize(V+1);
    depths.resize(V+1, 0);
    
   for (long long i = 1; i<V; i++)
   {
       parents[i] = i;
   }
}

long long Find(long long x)
{
    if (x==parents[x])
    {
        return x;
    }
    return parents[x] = Find(parents[x]);
}

bool Union(long long x, long long y)
{
    long long root1 = Find(x);
    long long root2 = Find(y);
    if (root1==root2)
    {
        return false;
    }
    
    if (depths[root1]<depths[root2])
    {
        swap(root1, root2);
    }
    
    if (depths[root1] == depths[root2])
    {
      depths[root1]++;
    }
    parents[root2] = root1;   
    return true;
}

int kruskal(vector<Edge>& edges, int V, int E)
{
   fillParents(V);
   sort(edges.rbegin(), edges.rend());
   int result = 0; 
    
    for (int i = 0; i<E; i++)
    {
        Edge currentEdge = edges[i];
        if (Union(currentEdge.from, currentEdge.to))
        {
            result+=currentEdge.weight;
        }
    }
    return result;
}
