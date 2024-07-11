#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX = 1000000;

long long parent[MAX];
long long depth[MAX];

struct Edge
{
   long long from;
   long long to;
  long long cost;
  long long profit;
    long long index;
    
    bool operator<(const Edge& other) const
    {
        if (this->cost == other.cost)
        {
            return this->profit>other.profit;
        }
        return this->cost<other.cost;
    }
};

int Find(int x)
{
    if (parent[x]==x)
    {
        //cout<<"sth"<<endl;
        return x;
    }
    //cout<<"sth"<<endl;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y)
{
    long long root1 = Find(x);
    long long root2 = Find(y);    
   
    if (root1==root2)
    {
        return false;
     }
    
    if (depth[root1]<depth[root2])
    {
        swap(root1, root2);
    }
    if (depth[root1]==depth[root2])
    {
        depth[root1]++;
    }
    parent[root2] = root1;
    //cout<<"sth"<<endl;
    return true;
}

void Kruskal(long long N, long long M, vector<Edge>& edges, vector<long long>& result)
{
    for(long long i = 0; i<=N; i++)
    {
        parent[i] = i;
        depth[i] = 1;
  }
    
    sort(edges.begin(), edges.end());
    
    for (long long i = 0; i<M; i++)
    {         
        if (Union(edges[i].from, edges[i].to))
        {
            result.push_back(edges[i].index);
        }
    }
}


int main() 
{
    long long N,M;
    cin>>N>>M;
    
    vector<Edge>edges;    
    
    for (long long i = 0; i<M; i++)
    {
        long long a, b, cost, profit;        
        cin>>a>>b>>cost>>profit;
        edges.push_back({a, b, cost, profit, i+1});
    }
    
    vector <long long> result;
    
    Kruskal(N, M, edges, result);
    
    size_t size = result.size();
    for (size_t i = 0; i<size; i++)
    {
        cout<<result[i]<<endl;
    }
}
