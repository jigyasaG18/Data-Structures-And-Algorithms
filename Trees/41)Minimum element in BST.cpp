Minimum element in BST
Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.

Examples
Input: root = [5, 4, 6, 3, N, N, 7, 1]
Output: 1

Input: root = [10, 5, 20, 2]
Output: 2

Input: root = [10, N, 10, N, 11]
             10
              \
               10
                \
                 11
Output: 10

class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        int mini=0;
        while(root!=NULL){
            mini=root->data;
            root=root->left;
        }
        return mini;
    }
};