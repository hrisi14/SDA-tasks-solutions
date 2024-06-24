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

bool ok(const vector<long long>& times, long long answer,long long pancakesNumber)
{
   size_t size = times.size();
    long long sum = 0;
    
    for (size_t i = 0; i<size; i++)
    {
        sum+=answer/times[i];
        
        if (sum>=pancakesNumber)
        {
            return true;
        }
   }
    return false;
}

long long binarySearch(const vector<long long>& times, long long l, long long r, long long pancakesNumber)
{
    long long answer = r;  
    while(l<=r)
    {
        long long mid = l + (r-l)/2;
        
        if (ok(times, mid, pancakesNumber))
        {  
            answer = min(answer, mid);
            r = mid - 1;            
        }
        else
        {
            l = mid+1;            
        }
    }
    return answer;
}

int main() 
{ 
    long long N, K;
    cin>>N>>K;
    vector<long long> times(K);
    
    for (long long i = 0; i<K; i++)
    {
        cin>>times[i];
    }
    
    auto slowest = max_element(times.begin(), times.end());
    auto fastest = min_element(times.begin(), times.end());
    
    long long l = (*fastest);
    long long r = N*(*slowest);
  
    cout<<binarySearch(times, l, r, N)<<endl;
}
