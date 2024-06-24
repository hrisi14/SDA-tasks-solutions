#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Guest
{
    int arrivalTime;
    int leaveTime;
    int guestIndex;
    int chairIndex; 
    
};

bool cmp(const Guest& lhs, const Guest& rhs)
{
    return lhs.arrivalTime<rhs.arrivalTime;
}

struct Compare
{
    bool operator()(const Guest& lhs, const Guest& rhs) const
{
    if (lhs.leaveTime==rhs.leaveTime)
    {
        return lhs.arrivalTime < rhs.arrivalTime;
    }
    return lhs.leaveTime>rhs.leaveTime;
}
};

priority_queue<Guest, vector<Guest>, Compare> pq;
priority_queue<int, vector<int>, greater<int>> chairsQ;


int getChairIndex(vector<Guest>& guests, vector<int>& chairs, int T, int N)
{
     for(long i = 0; i < N; i++) 
     {
        Guest g = guests[i];
       
        while(!pq.empty() && pq.top().leaveTime <= g.arrivalTime) 
        {
            Guest removed = pq.top();
            pq.pop();
            chairsQ.push(removed.chairIndex);
        }
        
         int freeChair = chairsQ.top();
         chairsQ.pop();
         pq.push({g.arrivalTime, g.leaveTime, g.guestIndex, freeChair});
         
         if (g.guestIndex==T)
         {
             return freeChair;
        }        
    }
    return 0;
}

int main() 
{
   int N;
    cin>>N;
    vector<Guest> guests;
    vector<int> chairs;
    
    for (int i = 0; i<N; i++)
    {
        int a, l;
        cin>>a>>l;
        guests.push_back({a, l, i, 0});
        chairs.push_back(i);
        chairsQ.push(i);
    }
    int T;
    cin>>T;
    sort(guests.begin(), guests.end(), cmp);    
    cout<<getChairIndex(guests, chairs, T, N)<<endl;
}
