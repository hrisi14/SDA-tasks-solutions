#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
const size_t MAX = 10000;

size_t parent[MAX];
size_t depth[MAX];

struct Edge
{
    size_t from;
    size_t to;
    size_t weight;    
    bool operator<(const Edge& other) const
    {
        return this->weight<other.weight;
    }
};

size_t Find(size_t x)
{
    if (parent[x]==x)
    {
        return x;
    }
    
    return parent[x] = Find(parent[x]);
}

bool Union(size_t x, size_t y)
{
    size_t root1 = Find(x);
    size_t root2 = Find(y); 
    
    if (root1==root2)
    {        
        return false;
    }   
     if (depth[root1]<depth[root2])
     {
         swap(root1, root2);
     }
     else if (depth[root1]==depth[root2])
     {
         depth[root1]++;
     }   
     parent[root2] = root1;
     return true;    
}

size_t kruskal(size_t N, size_t M, vector<Edge>& edges, size_t potentialMin, size_t startIndex)
{
     for (size_t i = 1; i<=N; i++)
    {
        parent[i] = i;
        depth[i] = 1;
    }    
    size_t potentialMax = potentialMin;
    size_t counter = 0;
    
      for(size_t i=startIndex; i<M; i++) 
      {       
        if(Union(edges[i].from, edges[i].to)) 
        {
            potentialMax = max(potentialMax, edges[i].weight);
            counter++;
       }       
    } 
    if (counter!=N-1) 
    {
         return 0;
   }
   return potentialMax;
}

pair<size_t, size_t> getRightAnswer(size_t N, size_t M, vector<Edge>& edges)
{
    pair<size_t, size_t> result;    
    size_t minDiff = INT_MAX;
    sort(edges.begin(), edges.end());
    size_t potentialMax = INT_MAX;
  
    for (size_t i = 0; i<M; i++)
    {       
        potentialMax = kruskal(N, M, edges, edges[i].weight, i);
        if (potentialMax==0)
        {
            break;
        }        
        size_t currentDiff = potentialMax - edges[i].weight;
        if (currentDiff<minDiff)
        {
            minDiff = currentDiff;
            result.first = edges[i].weight;
            result.second = potentialMax;
       }
    }
    return result;
}

int main() 
{
    size_t N, M;
    cin>>N>>M;    
    vector<Edge> edges;

    for (size_t i = 0; i<M; i++)
    {
        size_t from, to, velocity;
        cin>>from>>to>>velocity;
        edges.push_back({from, to, velocity});
  }  
    pair<size_t, size_t> result = getRightAnswer(N, M, edges);
    cout<<result.first<<" "<<result.second<<endl;
}
