Root to Node/Leaf Path in Binary Tree
Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.
Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.

Examples:
Input: root[] = [1, 2, 3, 4, 5]
ex-3
Output: [[1, 2, 4], [1, 2, 5], [1, 3]] 
Explanation: All possible paths: 1->2->4, 1->2->5 and 1->3

Input: root[] = [1, 2, 3]
       1
    /     \
   2       3
Output: [[1, 2], [1, 3]] 
Explanation: All possible paths: 1->2 and 1->3

Input: root[] = [10, 20, 30, 40, 60]
         10
       /    \
      20    30
     /  \
    40   60
Output: [[10, 20, 40], [10, 20, 60], [10, 30]]
Explanation: All possible paths: 10->20 ->40, 10->20->60 and 10->30

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int>x;
        if(root==NULL) return ans;
        getPath(root,ans,x);
        return ans;
    }
    bool getPath(Node* root, vector<vector<int>> &ans, vector<int> &x){
        if (!root) return false;  // If the current node is NULL, return
        
        x.push_back(root->data);  // Add the current node to the path
        
        // Check for leaf node
        if (!root->left && !root->right) { // Leaf node condition
            ans.push_back(x);    // Store the current path in the answer
        } else {
            // Recur for left and right subtrees
            getPath(root->left, ans, x);
            getPath(root->right, ans, x);
        }
        
        x.pop_back();  // Backtrack to explore other paths
    }
};