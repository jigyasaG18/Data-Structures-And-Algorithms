Construct the Binary Tree from Postorder and Inorder Traversal
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size())
            return NULL;
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root = build(inorder, 0, inorder.size() - 1, postorder, 0,
                               postorder.size() - 1, mpp);
        return root;
    }
    TreeNode* build(vector<int>& inorder, int instart, int inend,
                    vector<int>& postorder, int poststart, int postend,
                    map<int, int>& mpp) {
        if (instart > inend || poststart > postend)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postend]);
        int inroot = mpp[root->val];
        int numsleft = inroot - instart;
        root->left = build(inorder, instart, inroot - 1, postorder, poststart,
                           poststart + numsleft - 1, mpp);
        root->right = build(inorder, inroot + 1, inend, postorder,
                            poststart + numsleft, postend - 1, mpp);
        return root;
    }
};