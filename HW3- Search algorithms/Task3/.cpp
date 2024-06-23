#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <valarray>


bool check(const vector<size_t>& v, size_t target, size_t N, size_t T) 
{
    size_t teams = 0;
    size_t sum = 0;

    for (size_t i = 0; i<N; i++)
    {
        sum += v[i];

        if (v[i] > target) 
        {
            return false;
        }

        if (sum > target) 
        {
            teams++;
            sum = 0;
            i--;
        }        
    }
    teams++;
    return teams <= T;
}

size_t binarySearch(const vector <size_t>& v, size_t leftB, size_t rightB, size_t T, size_t N)
{    
    size_t left = leftB;
    size_t right = rightB;
    size_t ans = 0;
    while (left <= right)
    {
        size_t mid = left + (right - left) / 2;
        if (check(v, mid, N, T))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

size_t findSum(const vector<size_t>& v, size_t N)
{
    size_t sum = 0;
    for (size_t i = 0; i < N; i++)
    {
        sum += v[i];
    }
    return sum;
}

int main()
{
    size_t N, T;
    cin >> N;
    cin >> T;
    vector<size_t> skills;
    for (size_t i = 0; i < N; i++)
    {
        size_t s;
        cin>>s;
       skills.push_back(s);
    }
    
       size_t sumOfEl = findSum(skills, N);      
       size_t l  = 1;
    cout << binarySearch(skills,l, sumOfEl, T, N);
   
    return 0;
    
}  
