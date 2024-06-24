#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> graph;

int ccNumber = 0;

void dfs(int v, vector<bool>& visited, vector<int>& connectedComponents)
{
    visited[v] = true;
    connectedComponents[ccNumber]++;
    //cout<<ccNumber;
    
    for (auto neighbour: graph[v])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, visited, connectedComponents);
        }
    }
}

void connect(vector<bool>& visited, int N, vector<int>& connectedComponents)
{
    for (int i = 0; i<N; i++)
    {
         if (!visited[i])
        {
            
            dfs(i, visited, connectedComponents);
            ccNumber++;
        }
    }
}

int getGroupsCounter(int K, vector<int>& connectedComponents)
{
    int counter = 0;
    size_t size = connectedComponents.size();
    for (size_t i = 0; i<size; i++)
    {
        if (connectedComponents[i]!=0 && connectedComponents[i]%K==0)
        {
            counter++;
        }        
    }
    return counter;
}

int main() 
{
    int N, E, K;
    cin>>N>>E>>K;
     vector<int>connectedComponents (N, 0);
    vector<bool> visited(N, false);
    
    for (int i = 0; i<N; i++)
    {
        int from, to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
   }
    
    connect(visited, N, connectedComponents); 
   
    cout<<getGroupsCounter(K, connectedComponents);
}
