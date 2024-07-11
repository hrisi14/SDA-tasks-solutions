#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Group
{
    long long X;
    long long Y;
    long long K;

    Group() {}
    Group(long long X, long long Y, long long K) : X(X), Y(Y), K(K) {}
   
};

class Compare
{
public:
   bool operator()(Group g1, Group g2) 
   {
      if (g1.Y == g2.Y) 
     {
        return g1.X < g2.X;
    }
    return g1.Y > g2.Y;
}
};

bool cmp(Group g1, Group g2)
{   
    return g1.X < g2.X;
}

bool canAllPassengersGetOnBoard(const vector<Group>& passengers, priority_queue<Group, vector<Group>, Compare>& bus, long long& capacity)
{
    long long size = passengers.size();    
    long long busSum = 0; 
    
    for(long long i = 0; i < size; i++)
    {
        Group g = passengers[i];                
      
       while(!bus.empty() && bus.top().Y <= g.X) 
         {
           Group toRemove = bus.top();             
           busSum -= toRemove.K;           
           bus.pop();
        }              
     
        bus.push(g);        
        busSum += g.K;
            
        if (busSum>capacity)
        {
            return false;
        }
     }
    
    return busSum<=capacity;
}

int main()
{
    long long requests;
    cin >> requests;

    for (long long i = 0; i < requests; i++)
    {
        long long N, C;
        cin >> N >> C;
        
       
        vector<Group> passengers;

        for (long long j = 0; j < N; j++)
        {
            long long K, X, Y;
            cin >> K >> X >> Y;
            Group newGroup(X, Y, K);
            passengers.push_back(newGroup);
        }
         priority_queue<Group, vector<Group>, Compare> bus;
        sort(passengers.begin(), passengers.end(), cmp);           
        cout << canAllPassengersGetOnBoard(passengers, bus, C) << endl;
    }

}
