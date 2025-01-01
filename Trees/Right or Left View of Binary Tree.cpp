Right/Left View of Binary Tree
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
Example 1:(Right Side)
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        recursion(root,0,res);
        return res;
    }
    void recursion(TreeNode* root, int level, vector<int> &res){
        if(root==nullptr) return;
        if(res.size()==level){
            res.push_back(root->val);
        }
        recursion(root->right,level+1,res);
        recursion(root->left,level+1,res);
    }
};

For Left Side View:-
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        recursion(root,0,res);
        return res;
    }
    void recursion(TreeNode* root, int level, vector<int> &res){
        if(root==nullptr) return;
        if(res.size()==level){
            res.push_back(root->val);
        }
        recursion(root->left,level+1,res);
        recursion(root->right,level+1,res);
    }
};


