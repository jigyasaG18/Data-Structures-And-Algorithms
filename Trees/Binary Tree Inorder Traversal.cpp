Binary Tree Inorder Traversal
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

class Solution {
public:
void inorder(TreeNode* root, vector<int> &arr){
    if(root==nullptr){
        return;
    }
    inorder(root->left,arr);
    arr.push_back(root->val);
    inorder(root->right,arr);
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        return arr;
    }
};