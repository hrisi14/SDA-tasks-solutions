#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

const int MAX = 500000;

struct Guest
{
    long long guestIndex;
    long long arrivalTime;
    long long departureTime;
    long long chairIndex;
    
    Guest(long long guestIndex, long long arrivalTime, long long departureTime) :
       guestIndex(guestIndex), arrivalTime(arrivalTime), departureTime(departureTime)
    { }
};

class Compare
{
public:
    bool operator()(const Guest& left, const Guest& right)
    {
        if (left.departureTime == right.departureTime)
        {
            return left.arrivalTime < right.arrivalTime;
        }
        return left.departureTime > right.departureTime;
    }
};

bool cmp(const Guest& left, const Guest& right)
{
    return left.arrivalTime < right.arrivalTime;
}

long long findIndexOfChair(vector<Guest>& guests, priority_queue< Guest, vector<Guest>, Compare >& pqGuests, long long& T)
{
    priority_queue <int, vector<int>, greater <int>> freeChairs;
    
    for (int i = 0; i<MAX; i++)
    {
        freeChairs.push(i);
    }

    for (size_t i = 0; i < guests.size(); i++)
    {
        Guest g = guests[i];        
        
        while (!pqGuests.empty() && pqGuests.top().departureTime <= g.arrivalTime)
         {
            Guest toRemove = pqGuests.top();           
            freeChairs.push(toRemove.chairIndex);
            pqGuests.pop();   
        }
        
        g.chairIndex = freeChairs.top();
        freeChairs.pop();  
        pqGuests.push(g);
        
        if (g.guestIndex == T)
        {
            return g.chairIndex;                      
        }              
  }    
    return 0;    
}

int main()
{
    long long N;
    cin>>N;
    vector<Guest> guests;

    for (long long i = 0; i < N; i++)
    {
        long long arrivalTime, departureTime;
        cin >> arrivalTime >> departureTime;

        Guest newGuest(i, arrivalTime, departureTime);
        guests.push_back(newGuest);
    }
    
    long long T;
    cin>>T;
    
    sort(guests.begin(), guests.end(), cmp);
    priority_queue<Guest, vector<Guest>, Compare> pqGuests;
    cout << findIndexOfChair(guests, pqGuests, T) << endl;
}
