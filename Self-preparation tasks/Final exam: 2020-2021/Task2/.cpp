#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map <int, vector<int>> graph;

int ccNumber = 0;

void dfs(int startV, vector<bool>& visited,  vector<int>& cc)
{
    visited[startV] = true;
    cc[startV] = ccNumber;
    
    for (auto neighbour: graph[startV])
    {
        if(!visited[neighbour])
        {
          dfs(neighbour, visited, cc);   
         } 
    }
}

void connectedComponents(int V, vector<bool>& visited,  vector<int>& cc)
{
    for (int i = 1; i<=V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, cc);
            ccNumber++;
        }
    }
}

int main() 
{
    int V, E;
    int from, to;    
    cin>>V>>E;
    vector<bool> visited(V+1, false);
    vector<int> cc (V+1);
    
    for (int i = 0; i<E; i++)
    {       
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    } 
    
    connectedComponents(V, visited, cc);
    int K;
    cin>>K;
    for (int i = 0; i<K; i++)
    {
        cin>>from>>to;
       cout<<(cc[from]==cc[to])<<" ";       
    }
   
}
