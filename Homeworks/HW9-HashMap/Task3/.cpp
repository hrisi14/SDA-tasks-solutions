#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

int getMinDistance(const vector<int>& v)
{
    int minD = INT_MAX;
    size_t size = v.size();
    
    for (size_t i = 0; i<size-1; i++)
    {
        minD = min(minD, v[i+1]-v[i]);
    }
    return minD;
}

int main() 
{
    unordered_map <int, vector<int>> gossipMap;
    
    int N;
    cin>>N;
    
    for (int i = 0; i<N; i++)
    {
       int gossipyTopic;
       cin>>gossipyTopic;
        
       gossipMap[gossipyTopic].push_back(i);
    }
    
    int minDistance = INT_MAX;
    
    for (auto mapElement: gossipMap)
    {
        if (mapElement.second.size()>=2)
        {
            minDistance = min(minDistance, getMinDistance(mapElement.second));
        }
    }
    
    cout<<minDistance<<endl;
}
