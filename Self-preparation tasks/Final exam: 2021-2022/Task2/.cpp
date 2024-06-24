#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>


using namespace std;

/*struct Edge
{
    size_t to;
    size_t weight;
    
     bool operator>(const Edge& other) const 
     {
        return this->weight >= other.weight;
    }
    
};*/

/*struct Compare
{
    bool operator()(const pair<size_t, size_t>& lhs, const pair<size_t, size_t>& rhs) const
    {
        return lhs.first>rhs.first;
    }
};*/

unordered_map <size_t, vector<pair<size_t, size_t>>> graph;

void dijkstra(size_t startV, vector<size_t>& dist)
{
    dist[startV] = 0;
    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> pq;
    
    pq.push({dist[startV], startV});
        
    while(!pq.empty())
    {
        //cout<<"sth";
        pair<size_t, size_t> currentV = pq.top();
        pq.pop();
        
        if (dist[currentV.second]<currentV.first)
        {
            continue;
        }
        
        for (auto neighbour: graph[currentV.second])
        {
           if (dist[neighbour.second]>dist[currentV.second] + neighbour.first)
           {
               dist[neighbour.second]=dist[currentV.second] + neighbour.first;
               pq.push(make_pair(dist[neighbour.second], neighbour.second));
           }
        }
    }
}
