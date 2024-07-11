#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int counter(int a, int b, vector<int>& arr)
{
    auto  l = lower_bound(arr.begin(), arr.end(), a);
    auto  r = upper_bound(arr.begin(), arr.end(), b);
    int diff = r-l;
    if (diff<0)
    {
return 0;}
    return diff;
}

int main()
{
    int n; int q;
    cin>>n;
    cin>>q;
    
    vector<int> arr;
    for (int i = 0; i<n; i++)
    {
        int number;
        cin>>number;
        arr.push_back(number);
    }
 
     sort(arr.begin(), arr.end());
     for (int  i =0; i<q; i++)
   {
         int a, b;
         cin>>a;
         cin>>b;
         cout<<counter(a, b,arr)<<endl;         
   }
    
   
    
    
}
