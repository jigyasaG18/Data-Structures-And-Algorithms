Lowest Common Ancestor in a Binary Search Tree
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2

1st Way:-
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        int curr=root->val;
        if(curr<p->val && curr<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(curr>p->val && curr>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
};

2nd Way:-
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            if(root==NULL) return NULL;
            int curr=root->data;
            if(curr<n1 && curr<n2){
                return LCA(root->right,n1,n2);
            }
            if(curr>n1 && curr>n2){
                return LCA(root->left,n1,n2);
            }
            return root;
        }

};