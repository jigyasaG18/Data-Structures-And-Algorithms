Flatten Binary Tree to LinkedList
Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 
Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [0]
Output: [0]

1st Way:- Recursive
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
TreeNode* prev=nullptr;
    void flatten(TreeNode* root) {
        if (root == nullptr)
                return;

            // Traverse the tree in post-order (right first, then left)
            flatten(root->right);
            flatten(root->left);

            // Set the right pointer of the current node to the previously
            // processed node
            root->right = prev;
            root->left = nullptr; // Reset left pointer to null

            // Update prev to be the current node for the next call
            prev = root;
    }
};

2nd Way:- Iterative
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
    void flatten(TreeNode* root) {
         if (!root) return; // Handle empty tree

    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();

        // Push the right child first so that we process it after the left child
        if (curr->right) {
            st.push(curr->right);
        }
        if (curr->left) {
            st.push(curr->left);
        }

        // Set the current node's right child to the top of the stack
        if (!st.empty()) {
            curr->right = st.top();
        }
        curr->left = nullptr; // Set left to nullptr
    }
    }
};