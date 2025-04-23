Subtree of Another Tree
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false

class Solution {
    public:
    bool check(TreeNode* root1, TreeNode* root2){
        if(root1==nullptr && root2==nullptr) return true;
        if(root1==nullptr || root2==nullptr) return false;
        if(root1->val != root2->val) return false;
        return (check(root1->left,root2->left) && check(root1->right,root2->right));
    }
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            if(root==NULL) return false;
            if(check(root,subRoot)) return true;
            return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
        }
    };