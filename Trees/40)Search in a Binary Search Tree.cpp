Search in a Binary Search Tree
You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

Example 1:
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:
Input: root = [4,2,7,1,3], val = 5
Output: []
 
1st Way:-
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=nullptr && root->val!=val){
            root=val<root->val?root->left:root->right;
        }
        return root;
    }
};

2nd Way:-
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=nullptr && root->val!=val){
            if(val<root->val){
                root=root->left;
            }
            else root=root->right;
        }
        return root;
    }
};