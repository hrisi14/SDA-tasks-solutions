#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;

unordered_map <size_t, vector<size_t>> graph;
queue<size_t>targetOrder;
set<size_t> targetVertices;
set<size_t> forbiddenVertices;

size_t bfs(size_t& startV, size_t& endV, size_t& N)
{   
    queue<size_t> q;
    q.push(startV);
    size_t result = 0;
    
    while (!q.empty())
    {
        size_t qSize = q.size();
        result++;
         
        for (size_t i = 0; i<qSize; i++)
    {        
        size_t currentV = q.front();
             q.pop();
                
            for (const auto& neighbour: graph[currentV])
        {         
                if (neighbour == endV)   
            {
                return result;
            }
                if (forbiddenVertices.find(neighbour)==forbiddenVertices.end() && targetVertices.find(neighbour)==targetVertices.end())
                {
                    q.push(neighbour);
                }
            }
        }
    }
    
    return 0;
}

size_t getShortestPath(size_t& N)
{
    size_t from = targetOrder.front();
    targetOrder.pop();
    size_t result = 0;
    targetVertices.erase(from);
    
    while (!targetOrder.empty())
    {
       size_t to = targetOrder.front();
        targetOrder.pop();
          
        targetVertices.erase(to);
        result+=bfs(from, to, N);
      
        from = to;
   }    
    return result;
}

int main() 
{
    size_t N, M, P, K;
    cin>>N>>M;
    
    for (size_t i = 0; i<M; i++)
    {
       size_t a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
  }
    cin>>P;
    for (size_t i = 0; i<P; i++)
    {
       size_t v;
        cin>>v;
        targetOrder.push(v);
        targetVertices.insert(v);
   }
    cin>>K;
    for (size_t i = 0; i<K; i++)
   {
       size_t v;
        cin>>v;
        forbiddenVertices.insert(v);
  }
    
    cout<<getShortestPath(N);
}
