#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const long long MAX = 1000000;

struct Node
{
    long long left;
    long long right;
    long long value;
  
};

  Node nodes[MAX];
long long leftSums[MAX]{0};
long long rightSums[MAX]{0};
long long rootSum = 0;

void findSums(Node* root, int index)
{
    if (!root)
    {
        return;
    }
    
    if (index==0)
    {
        rootSum+=root->value;
    }
    else if (index<0)
    {
        leftSums[-index - 1] += root->value;
    }
    else
    {
        rightSums[index-1]+=root->value;
    }
    
    if (root->left!=-1)
    {
        findSums(nodes + (root->left), index-1);
    }
    if (root->right!=-1)
    {
        findSums(nodes + (root->right), index+1);
    }
}

int main()
{
    
    int N;
    cin>>N;
    
    for (int i = 0; i<N; i++)
    {
        cin>>nodes[i].value>>nodes[i].left>>nodes[i].right;
    }
    long long index = 0;
    
    findSums(nodes, index);
        
    for (int i = MAX-1; i>=0; i--)
    {
        if (leftSums[i]!=0)
        {
            cout<<leftSums[i]<<" ";
        }
    }    
     cout<<rootSum<<" ";
    for (int i = 0; i<MAX; i++)
    {
        if (rightSums[i]!=0)
        {
            cout<<rightSums[i]<<" ";
        }
    }
}
