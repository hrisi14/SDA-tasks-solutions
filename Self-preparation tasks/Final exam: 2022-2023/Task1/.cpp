#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map <int,int> stickers;

int main() 
{
   int N;
    cin>>N;
  
    vector<int> stickersOnly(N);
    
    for (int i = 0; i<N; i++)
    {     
       cin>>stickersOnly[i];       
    }
    
    int fightCounter = 0;
    for (int i = 0; i<N; i++)
    {        
        stickers[stickersOnly[i]]++;
        
        int currentSticker;
        cin>>currentSticker;
        
        if (stickers[currentSticker]==0)
        {         
            fightCounter++;           
        } 
       else
       {
           stickers[currentSticker]--;
       }        
    }
    
    cout<<fightCounter<<endl;    
}
