Delete a Node in Binary Search Tree
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove. If the node is found, delete the node.

Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:
Input: root = [], key = 0
Output: []

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->val==key) return helper(root);
        TreeNode* dnode=root;
        while(root!=nullptr){
            if(root->val>key){
                if(root->left!=nullptr && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{ //root->val<key
            if(root->right!=nullptr && root->right->val==key){
                root->right=helper(root->right);
                break;
            }
            else{
                root=root->right;
            }
            }
        }
        return dnode;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==nullptr) return root->right;
        if(root->right==nullptr) return root->left;
        TreeNode* rightchild=root->right;
        TreeNode* lastright=find(root->left);
        lastright->right=rightchild;
        return root->left;
    }
    TreeNode* find(TreeNode* root){
        if(root->right==nullptr) return root;
        return find(root->right);
    }
};