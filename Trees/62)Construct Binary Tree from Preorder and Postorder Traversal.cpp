Construct Binary Tree from Preorder and Postorder Traversal
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
If there exist multiple answers, you can return any of them.

Example 1:
Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

Example 2:
Input: preorder = [1], postorder = [1]
Output: [1]

1st Way:-
class Solution {
    public:
    TreeNode* buildTreeFromPrePost(vector<int>& preorder, vector<int>& postorder, int& preIndex, int left, int right) {
            if (preIndex >= preorder.size() || left > right) {
                return nullptr;
            }
            // Create the root node from the preorder
            TreeNode* root = new TreeNode(preorder[preIndex]);
            preIndex++; // Move to the next index in preorder
    
            // Base case when the node has no children
            if (left == right) {
                return root;
            }
    
            // Find the index of the next value in postorder
            int postIndex;
            for (postIndex = left; postIndex <= right; postIndex++) {
                if (postorder[postIndex] == preorder[preIndex]) {
                    break;
                }
            }
            // Recursively build the left and right subtrees
            root->left = buildTreeFromPrePost(preorder, postorder, preIndex, left, postIndex);
            root->right = buildTreeFromPrePost(preorder, postorder, preIndex, postIndex + 1, right - 1);
    
            return root;
        }
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int preIndex = 0; // Start index in preorder
            return buildTreeFromPrePost(preorder, postorder, preIndex, 0, postorder.size() - 1);
        }
    };
    
2nd Way:-
class Solution {
int pre_idx=0;
    int post_idx=0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* curr = new TreeNode(preorder[pre_idx]); //root node
        pre_idx++;

        if(curr->val != postorder[post_idx])
            curr->left = constructFromPrePost(preorder,postorder);
        if(curr->val != postorder[post_idx])
            curr->right = constructFromPrePost(preorder,postorder);
        
        post_idx++;
        return curr;
    }
};
