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
    int kg;
    int time;

    Node()
    {
    }

    Node(int newD, int newKg, int newT) : destination(newD), kg(newKg), time(newT)
    {
    }
  
     
bool operator>(const Node& other) const
    {
        return this->time > other.time;
    }
};

  


unordered_map<int, vector<Node>> graph;

bool shortestPath(int& startStop, int& endStop, int& kg, vector<int>& times,  int& neededTime)
{
   for (size_t i = 0; i<times.size(); i++)
   {
       times[i] = INT_MAX;
    }
    times[startStop] = 0;
    priority_queue<Node, vector<Node>, greater<Node>>pq;    
    pq.push({startStop, 0, 0});   

    while (!pq.empty())
    {     
        Node currentNode = pq.top();
        pq.pop();
        
        int currentV = currentNode.destination;
        int currentTime = currentNode.time;
        int currentKg = currentNode.kg;  
        for (const auto& neighbour : graph[currentV])
        {            
                         
                if (times[neighbour.destination] > times[currentV] + neighbour.time   && neighbour.kg<=kg)
                {                     
                       
                       times[neighbour.destination] = times[currentV] + neighbour.time;  
                       pq.push({ neighbour.destination, neighbour.kg, times[neighbour.destination]});                                  }
            
        }
            
    }    
    return (times[endStop] <= neededTime);
}

int binarySearch(int startStop, int endStop, vector<int>& times, int neededTime, int l, int r)
{
   int  result = INT_MAX;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (shortestPath(startStop, endStop, mid, times,  neededTime))
        {
            result = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return result;
}

int main()
{
    int N, M, neededTime;
    cin >> N >> M >> neededTime;

    vector<int> times(N + 1, INT_MAX);
    vector<bool> visited(N + 1, false);
    int s = 1;
    int r = 0;
    int l = 1;
    
    
    
    for (int i = 0; i<M; i++)
    {
        int u, v, kg, t;
        cin >> u >> v >> kg >> t;
        Node newCrossroad;
        newCrossroad.destination = v;
        newCrossroad.kg = kg;
        newCrossroad.time = t;
        graph[u].push_back(newCrossroad);        
        r = max(r, kg);       
    } 
  
    //jUST TESTING 
    
    int result = binarySearch(s, N, times, neededTime, 0, r);
    
    int kg = 6;
  
    
    if (result != INT_MAX)
    {
        cout << result;
    }
    else
    {
        cout << -1;
    }
}
