Construct Binary Tree from Inorder and Preorder Traversal
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root = build(preorder, 0, preorder.size() - 1, inorder, 0,
                               inorder.size() - 1, mpp);
        return root;
    }
    TreeNode* build(vector<int>& preorder, int prestart, int preend,
                    vector<int>& inorder, int instart, int inend,
                    map<int, int>& mpp) {
        if (prestart > preend || instart > inend)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = mpp[root->val];
        int numsleft = inroot - instart;
        root->left = build(preorder, prestart + 1, prestart + numsleft, inorder,
                           instart, inroot - 1, mpp);
        root->right = build(preorder, prestart + numsleft + 1, preend, inorder,
                            inroot + 1, inend, mpp);

        return root;
    }
};