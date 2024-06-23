#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<string>
using namespace std;


int main() 
{
   string s1, s2;    
   cin>>s1>>s2;
    
    long long counter = 0;
    
    size_t stringLength = s2.size();
    for (size_t i = 0; i<stringLength; i++)
    {
        if (s2[i]==s1[0])
        {
            size_t firstString = s1.size();
            size_t iter = i;
            bool flag = true;
            
            for (size_t j = 0; j<firstString; j++)
            {
                if (s1[j]!=s2[iter])
                {
                  flag = false;
                  break;
                }                    
                iter++;                
            }
            if (flag)
            {
                counter++;
            }
        }
    }
    
    cout<<counter<<endl;    
}
