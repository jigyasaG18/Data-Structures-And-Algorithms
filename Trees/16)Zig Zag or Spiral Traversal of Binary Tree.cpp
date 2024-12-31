Zig Zag / Spiral Traversal of Binary Tree
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

1st Way:-
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==nullptr) return result;
        queue<TreeNode*>q;
        q.push(root);
        bool lefttoRight=true;
        while(!q.empty()){
        int size=q.size();
        vector<int>ans(size);
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();

            int index=(lefttoRight) ? i : (size-i-1) ;
            ans[index]=node->val;

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        lefttoRight=!lefttoRight;
        result.push_back(ans);
        }
        return result;
    }
};

2nd Way:-
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	 vector<int> result; // Correctly define the result vector
    if (root == NULL) return result;
    
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> ans(size);
        
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            
            int index = (leftToRight) ? i : (size - i - 1);
            ans[index] = node->data; // Use node->data instead of root->data
            
            // Push the left and right children of the current node
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        
        leftToRight = !leftToRight; // Toggle the direction
        // Append current level result to the final result
        // For appending elements from ans to result
            for (int value : ans) {
                result.push_back(value); // Append each value from ans to result
            }
    }
    
    return result;
    }
    };