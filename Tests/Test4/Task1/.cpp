#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long findDays(priority_queue<int, vector<int>, greater<int>>& pq, long long& S)
{
    long long days = 0;
    
    while(pq.top()<S)
    {
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();
        
        int s3 = s1 + 2*s2;
        pq.push(s3);
        days++;
        if (pq.size()<2)
        {
            return -1;
         }
     }
    return days;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   long long N; long long S;
    cin>>N>>S;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (long long i = 0; i<N; i++)
    {
        int n;
        cin>>n;
        pq.push(n);
     }
    
    cout<<findDays(pq, S);
}
