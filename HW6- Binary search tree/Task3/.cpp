#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const long long MAX_SIZE = 4*1000000;
struct Node
{
    int value;
    Node* left;
    Node* right;
};

Node nodes[MAX_SIZE];

long long maxValueTree(Node* root)
{
    if (!root)
    {
        return 0;
    }
   // long long maxValueLeft = maxValueTree(root->left);
   // long long maxValueRight = maxValueTree(root->right);
    return max(maxValueTree(root->left), maxValueTree(root->right)) + root->value;
}

void findMax(Node* root, long long& maxValue)
{
    if (!root)
    {
       return; 
    }
    
    long leftSum = maxValueTree(root->left);
    long rightSum = maxValueTree(root->right); 
        if (leftSum<0)
        {
            leftSum = 0;
        }
        if (rightSum<0)
        {
            rightSum = 0;
        }
     long long newMax = leftSum + root->value + rightSum;

        if (newMax > maxValue)
        {
            maxValue = newMax;
        }
    
    findMax(root->left, maxValue);
    findMax(root->right, maxValue);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int l, r;
        cin >> nodes[i].value >> l >> r;

        if (l != -1)
        {
            nodes[i].left = &nodes[l];
        }
        else
        {
            nodes[i].left = nullptr;
        }

        if (r != -1)
        {
            nodes[i].right = &nodes[r];
        }
        else
        {
            nodes[i].right = nullptr;
        }
    }
    long long result = 0;
    findMax(nodes, result);
    cout<<result;
}
