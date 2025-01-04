Ceil in a Binary Search Tree
Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.
If Ceil could not be found, return -1.

Example 1:
Input: root = [5, 4, 6, 3, N, N, 7, 1], X = 3
      5
    /   \
   1     7
    \
     2 
      \
       3
Output: 3
Explanation: We find 3 in BST, so ceil of 3 is 3.

Example 2:
Input: root = [10, 5, 11, 4, 7, N, N, N, N, N, 8], X = 6
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8
Output: 7
Explanation: We find 7 in BST, so ceil of 6 is 7.

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    int ceil=-1;
    while(root){
        if(root->data==input){
            ceil=root->data;
            return ceil;
        }
        if(root->data<input){
            root=root->right;
        }
        else { //root->data>input
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}