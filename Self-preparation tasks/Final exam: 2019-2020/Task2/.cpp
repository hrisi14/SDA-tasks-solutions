#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
   int N;
   cin>>N;
   vector <int> arr;
   for (int i = 0; i<N; i++)
   {
       int n;
       cin>>n;
       arr.push_back(n);
   }
    
    int Q;
    cin>>Q;
    for (int i = 0; i<Q; i++)
    {
        int n;
        cin>>n;
        auto l = lower_bound(arr.begin(), arr.end(), n);
        auto r = upper_bound(arr.begin(), arr.end(), n);
        if (*l!=n)
        {
            cout<< (l - arr.begin())<<endl;
        }
        else
        {
            cout<<(l-arr.begin())<<" "<<(r - arr.begin() - 1)<<endl;
        }
    }
}
