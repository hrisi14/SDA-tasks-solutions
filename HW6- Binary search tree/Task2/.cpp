#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const long long MAX = 1000000;
struct Node
{
    Node* left = nullptr;
    Node* right = nullptr;
    long long index;   
};

Node nodes[MAX];

long long findElements(Node* root)
{
    if (!root)
    {
        return 0;
    }
   return findElements(root->left) + findElements(root->right) + 1;
}

long long findMax(long long N)
{  
    long long result = 0;
    
    for (long long i = 0; i<N; i++)
    {
        long long l = findElements(nodes[i].left);
        long long r = findElements(nodes[i].right);
        long long diff = N-l-r-1;
    if (l==0)
    {
        l = 1;
    }
    if (r==0)
    {
        r = 1;
    }
     
        if (diff==0)
        {
            diff = 1;
        }
        long long currentResult = l*r*diff;        
        
        if (result<currentResult)
        {
            result = currentResult;
        }
    }    
    return result;
}

int main() 
{
  long long N;
  cin>>N;
   
    for (long long i = 0; i<N; i++)
    {
        nodes[i].index = i;
        long long l, r;
        cin>>l>>r;
        
        if (l!=-1)
        {
            nodes[i].left = &nodes[l];            
        }
        else
        {
            nodes[i].left = nullptr;            
        }        
         if (r!=-1)
        {
            nodes[i].right = &nodes[r];           
        }
        else
        {
            nodes[i].right = nullptr;
        }
    }    
   
    
         cout<<findMax(N);
    
   
}
