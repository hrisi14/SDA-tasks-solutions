#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>
#include <climits>
using namespace std;

unordered_map <size_t, vector<size_t>> graph;
queue<size_t>targetOrder;
set<size_t> targetVertices;  



int bfs(int startV, int endV)
{
    int currentResult = 0;    
    queue<size_t> bfsQ;
    bfsQ.push(startV);
  
    while(!bfsQ.empty())
    {
        currentResult++;        
        size_t qSize = bfsQ.size();        
        for (size_t i = 0; i<qSize; i++)
      {          
       size_t currentV = bfsQ.front();
        bfsQ.pop();                
     
        for (const auto& neighbour: graph[currentV])
        {       
            if (neighbour==endV)
           {
                return currentResult;
            }
            if (targetVertices.find(neighbour)==targetVertices.end())
          {      
              
                bfsQ.push(neighbour);               
            }
        }
      }
    }
    return -1;
}

int getShortestPath()
{
    int currentStart, currentEnd;
    
    currentStart = targetOrder.front();
    targetOrder.pop();
    targetVertices.erase(currentStart);
    int result = 0;
    
    while(!targetOrder.empty())
    {
        currentEnd = targetOrder.front();        
        targetOrder.pop();
        
        targetVertices.erase(currentEnd);
        int currentResult = bfs(currentStart, currentEnd);
        if (currentResult == -1)
        {
            return -1;
        }
        result += currentResult;
        currentStart = currentEnd;
   }
   return result;
}

int main() 
{
    size_t N, M;
    cin>>N>>M;
    
    size_t startV, nextV;
    cin>>startV>>nextV;
    graph[startV].push_back(nextV);
   
    for (size_t i = 1; i<M-1; i++)
     {
        size_t a, b;
        cin>>a>>b;
        graph[a].push_back(b);       
    }
    
    size_t  penultimate, endV;
    cin>>penultimate>>endV;
    graph[penultimate].push_back(endV);  
   
    size_t K; 
    cin>>K;    
    
    for (size_t i = 0; i<K; i++)
    {
        size_t v;
        cin>>v;
        targetVertices.insert(v);
        targetOrder.push(v);
    }
   
    cout<<getShortestPath();
}
