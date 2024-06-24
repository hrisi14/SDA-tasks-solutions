#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

   void bfsPrinter()
   {
       queue<Node*> q;
       //Node* current = root;
       
       q.push(root);
       
       while (!q.empty())
       {
           size_t size = q.size();
           cout<<q.front()->value<<" ";
               
           for (size_t i = 0; i<size; i++)
           {
               Node* current = q.front();
               q.pop();
               //cout<<"Current level's node: "<<current->value<<endl;
                   
               if (current->left)
               {
                   q.push(current->left);
               }
               if (current->right)
               {
                   q.push(current->right);
               }
           }
       }
   }
    
    void printLeftProfile()
    {
        bfsPrinter();
    }

private:
  	
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) 
    {
        cin >> value;
        tree.insert(value);
    }
    tree.printLeftProfile();
    return 0;
}
