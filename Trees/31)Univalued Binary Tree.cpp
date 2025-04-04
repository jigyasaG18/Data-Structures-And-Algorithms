Univalued Binary Tree
A binary tree is uni-valued if every node in the tree has the same value.
Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

Example 1:
Input: root = [1,1,1,1,1,null,1]
Output: true

Example 2:
Input: root = [2,2,2,5,2]
Output: false

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
void tree(TreeNode* root, int n, bool &flag){
    if(!root) return;
    if(root->val!=n){
        flag=false;
        return;
    }
    tree(root->left,n,flag);
    tree(root->right,n,flag);
}
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        bool flag=true;
        int n=root->val;
        tree(root,n,flag);
        return flag;
    }
};