Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
          int diameter = 0; // To store the maximum diameter
        height(root, diameter); // Compute diameter during depth calculation
        return diameter;
    }
    //Function to calculate max depth and update diameter
    int height(TreeNode* root, int &diameter) {
        if (root == NULL) return 0; 
        
        // Recursively calculate the height of left and right subtrees
        int lh = height(root->left, diameter); 
        int rh = height(root->right, diameter); 
        
        // Update the maximum diameter found so far
        diameter = max(diameter, lh + rh);

        // Return the height of the current node
        return 1 + max(lh, rh); 
    }
};