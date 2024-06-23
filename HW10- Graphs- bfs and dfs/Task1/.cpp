#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>

using namespace std;

unordered_map<size_t, unordered_map<size_t, bool>> forest;

struct Tree
{
    size_t row, column;
};

bool validate(const Tree& tree, size_t numberSize)
{
    return 0 <= tree.row && tree.row < numberSize && 0 <= tree.column &&
        tree.column < numberSize;
}

size_t findCurrentArea(unordered_map<size_t, unordered_map<size_t, bool>>& forest, size_t row, size_t column, size_t numberSize)
{
    size_t top = row, bottom = row, left = column, right = column;
    stack<Tree> s;
    s.push(Tree({row, column}));
    
    while(!s.empty())
    {
        Tree burningTree = s.top();
        s.pop();
        size_t r = burningTree.row;
        size_t c = burningTree.column;      
        
        if (forest[r][c]==true)
        {
            forest[r][c] = false; ///!!!
            top = min(top, r);
            bottom = max(bottom, r);
            left = min(left, c);
            right = max(right, c);            
             for (const Tree& tree :
            {
               Tree{burningTree.row - 1, burningTree.column},
               Tree{burningTree.row + 1, burningTree.column},
               Tree{burningTree.row, burningTree.column - 1},
               Tree{burningTree.row, burningTree.column + 1} })
         {          
            if (validate(tree, numberSize) && forest[tree.row][tree.column]==true)
            {
               s.push(tree);
            }
          }  
      }
    }
     return (bottom - top + 1)*(right - left + 1);
} 
int main()
{
    size_t numberSize;
    cin >> numberSize;

    queue<Tree> burningTrees;
    vector <size_t> burningAreas;

    for (size_t i = 0; i < numberSize; i++)
    {
        for (size_t j = 0; j < numberSize; j++)
        {
            bool value;
            cin >> value;
            forest[i][j] = value;
            if (value)
            {
                burningTrees.push(Tree({ i, j }));
            }           
        }
    }
    for (size_t i = 0; i<forest.size(); i++)
    {
        for (size_t j = 0; j<forest.size(); j++)
      {
            if (forest[i][j])
            {
               size_t currentArea = findCurrentArea(forest, i, j, numberSize);
               burningAreas.push_back(currentArea);    
            }
         }
    }
    sort(burningAreas.rbegin(), burningAreas.rend());
    size_t vSize = burningAreas.size();
    for (size_t i = 0; i < vSize; i++)
    {
        cout << burningAreas[i] << " ";
    }   
}
