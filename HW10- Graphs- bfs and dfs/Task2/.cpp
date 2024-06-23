#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

unordered_map<int, vector<int>> graph;


int bfsToNode(int v, int N, vector <int> dist, vector<int> groups)
{
    queue<int>q;
    vector<bool> visited(N+1, false);   
    
    visited[v] = true;
    dist[v] = 0;
    q.push(v);
    int visitedNodes = 1;

    int top = q.front();
    dist[top] = 0;
  
    while (!q.empty()) 
    {
        if (visitedNodes == N) 
        {
            break;
        }        
        top = q.front();
        q.pop();
        for (int w : graph[top])
        {
             if (!visited[w]) 
            {
                visited[w] = true;
                 
                dist[w] = min(dist[w], dist[top] + 1);
                 if (groups[w]==groups[v])
                 {
                     return dist[w];
                 }
                q.push(w);
                visitedNodes++;
           }
        }
    }
    return dist[top];
}

int findMinDistance(vector<int> groups, int searchedGroup, int N)
{
    vector<int> dist(N + 1, INT_MAX);    
    int minDistance = INT_MAX;
   
    for (int i = 1; i <= N; i++)
    {      
         if (groups[i] == searchedGroup)
        {   
            int distFromThisNode = bfsToNode(i, N, dist, groups);
            minDistance = min(minDistance, distFromThisNode);
        }
    }
    return minDistance;
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<int> groups(N + 1);

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= N; i++)
    {
        int groupNumber;
        cin >> groupNumber;
        groups[i] = groupNumber;
    }
    int searchedGroup;
    cin >> searchedGroup;

    cout << findMinDistance(groups, searchedGroup, N);
}
