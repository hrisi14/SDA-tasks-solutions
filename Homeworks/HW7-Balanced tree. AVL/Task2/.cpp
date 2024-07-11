#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int countSubarraysWithOddLength(vector<int>& arr, int med) 
{
    size_t  size = arr.size();
    int ind = -1;
    
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == med)
        {
            ind = i;            
        }
    }
    if (ind == -1)
    {
        return -1;
    }
    unordered_map<int, int>myMap;
    int diff = 0;
    myMap[0]++;

    for (size_t i = ind + 1; i < size; i++) 
    {
        if (arr[i] < med)
        {
            diff--;
            
        }
        else if (arr[i] > med)
        {
            diff++;          
        }
        myMap[diff]++;
}
    diff = 0;
    int ans = 0;
   
    for (int i = ind; i >= 0; i--)
    {
        if (arr[i] > med)
        {
            diff++;          
        }
        else  if (arr[i] < med)
        {
            diff--;            
        }
        ans += myMap[0 - diff];  
}
    return ans;
}


int main() 
{
     int M; int B;
    cin >> M;
    cin >> B;
    vector <int> nums;

    for (int i = 0; i < M; i++)
    {
        int number;
        cin >> number;
        nums.push_back(number);
    }
    
    cout<<countSubarraysWithOddLength(nums, B);
}
