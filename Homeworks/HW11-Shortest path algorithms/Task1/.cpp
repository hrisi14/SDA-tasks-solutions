#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node
{
    int destination;
    int weight;

    bool operator>(const Node& other) const
    {
        return this->weight > other.weight;
    }
};

struct BusStop
{
    vector<Node> adjList;
    int interval;
};

int shortestPath(int& startStop, int& endStop, vector<BusStop>& graph, vector<int>& dist)
{
    dist[startStop] = 0;

    priority_queue<Node, vector<Node>, greater<Node>>pq;
    pq.push({ startStop, 0 });

    while (!pq.empty())
    {
        Node currentNode = pq.top();
        pq.pop();
        int currentV = currentNode.destination;   
        int currentDist = currentNode.weight;
       
         if (currentDist > dist[currentV]) 
        {
            continue;
        }
        
        for (const auto& neighbour : graph[currentV].adjList)
        {    
            //cout<<"Neighbour "<<neighbour.destination<<endl;
            int currentTime = currentDist;
            int timeWait = currentTime % graph[currentV].interval;
                     
            timeWait = timeWait ? graph[currentV].interval - timeWait : timeWait;  //???     
            
            currentTime += timeWait + neighbour.weight;            
                           
            if (dist[neighbour.destination] > currentTime) 
            {
               
                dist[neighbour.destination] = currentTime;
               pq.push({neighbour.destination, currentTime});
            }                    
        }
    }
    return dist[endStop];
}

int main()
{
    int V, E, s, e;
    cin >> V >> E >> s >> e;

    vector<BusStop> graph(V);

    vector<int> dist(V + 1, INT_MAX);
    vector<int> intervals(V);

    for (int i = 0; i < V; i++)
    {
        int interval;
        cin >> interval;
        graph[i].interval = interval;
    }

    for (int i = 0; i < E; i++)
    {
        int startStop, endStop, weight;
        cin >> startStop >> endStop >> weight;
        graph[startStop].adjList.push_back({ endStop, weight });
    }
    int result = shortestPath(s, e, graph, dist);
    if (result != INT_MAX)
    {
        cout<<result;
    }
    else
    {
        cout<<-1;
    }
}
