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

struct Pair
{
    int ID; 
    int time;
};

unordered_map<int, int> mostSold;  
unordered_map <int, int> countersContainer;
vector<int> times;
vector<Pair> input;

int main() 
{
    int N;
    cin>>N;
    for (int i = 0; i<N; i++)
     {
        int ID, TIME;
        cin>>ID>>TIME;
        times.push_back(TIME);
        input.push_back({ID, TIME});
    }
   
    
    int maxCounter = 0;
    int IDofMax = input[0].ID;
    
    //A precalculation in advance!!! - a common method in tasks with a sequence of requests
    for (int i = 0; i<N; i++)
   {
        countersContainer[input[i].ID]++;
        if (countersContainer[input[i].ID]>=maxCounter)
        {
            maxCounter = countersContainer[input[i].ID];
            IDofMax = input[i].ID;
        }

         mostSold[input[i].time] = IDofMax;        
      }
    
    vector<int> result;
    int Q;
    cin>>Q;     
    
    for (int i = 0; i<Q; i++)
 {        
        int q;
        cin>>q;
        auto realTime = lower_bound(times.begin(), times.end(), q);
        
        if (realTime==times.begin() && times[0]>q)
        {
            result.push_back(-1);
        }
        else if (realTime==times.begin() && times[0]==q)
        {
            result.push_back(mostSold[*realTime]);
        }
        else
        {
            if (*realTime==q)
            {
                result.push_back(mostSold[*realTime]);
                continue;
            }
            --realTime;
            result.push_back(mostSold[*realTime]);
       }      
    }
    size_t resSize = result.size();
    
    for (size_t i = 0; i<resSize; i++)
    {
        cout<<result[i]<<endl;
   }    
}
