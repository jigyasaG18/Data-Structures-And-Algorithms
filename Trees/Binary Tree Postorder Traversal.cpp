Binary Tree Postorder Traversal
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

class Solution {
public:
void postorder(TreeNode* root, vector<int> &arr){
  if(root==nullptr){
    return;
  }
  postorder(root->left,arr);
  postorder(root->right,arr);
  arr.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>arr;
        postorder(root,arr);
        return arr;
    }
};