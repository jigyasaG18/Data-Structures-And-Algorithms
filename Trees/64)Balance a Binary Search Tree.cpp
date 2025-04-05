Balance a Binary Search Tree
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Example 1:
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:
Input: root = [2,1,3]
Output: [2,1,3]

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
     vector<int> nodes; // Vector to hold the nodes' values
    
        void inOrderTraversal(TreeNode* root) {
            if (!root) return;
            inOrderTraversal(root->left);
            nodes.push_back(root->val);
            inOrderTraversal(root->right);
        }
    
        TreeNode* sortedArrayToBST(int left, int right) {
            if (left > right) return nullptr;
            int mid = left + (right - left) / 2; // Pick the middle element for balanced BST
            TreeNode* node = new TreeNode(nodes[mid]); // Create the node
            node->left = sortedArrayToBST(left, mid - 1); // Recursively construct the left subtree
            node->right = sortedArrayToBST(mid + 1, right); // Recursively construct the right subtree
            return node;
        }
        TreeNode* balanceBST(TreeNode* root) {
               inOrderTraversal(root); // Collect values in sorted order
            return sortedArrayToBST(0, nodes.size() - 1); // Build the balanced BST
        }
    };