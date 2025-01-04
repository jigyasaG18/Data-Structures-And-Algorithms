Check if a tree is a BST or BT / Validate Binary Search Tree
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validBST(root, long(INT_MIN) - 1, long(INT_MAX) + 1);
    }
    bool validBST(TreeNode* root, long minval, long maxval) {
        if (root == nullptr) return true;
        // Checking if the current node's value is within the valid range
        if (root->val <= minval || root->val >= maxval) return false;
        // Recursively checking the left and right subtrees
        return validBST(root->left, minval, root->val) &&
               validBST(root->right, root->val, maxval);
    }
};