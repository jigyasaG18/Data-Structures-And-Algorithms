Kth Smallest Element in a BST
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 
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
    int kthSmallest(TreeNode* root, int k) {
        int kSmallest = INT_MAX;
        // Counter to track visited nodes
        int counter = 0; 

        // Find Kth smallest element
        // (perform inorder traversal)
        inorder(root, counter, k, kSmallest);
        return kSmallest;
    }
      void inorder(TreeNode* root, int& counter, int &k, int& kSmallest) {
        if (!root || counter >= k) return;

        // Traverse left subtree
        inorder(root->left, counter, k, kSmallest);

        // Increment counter after visiting left subtree
        counter++;

        // Check if current node is the Kth smallest
        if (counter == k) {
            kSmallest = root->val;
            return;
        }

        // Traverse right subtree if
        // Kth smallest is not found yet
        inorder(root->right, counter, k, kSmallest);
    }
};

2nd Way:-
class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
         int ksmall = INT_MAX; // Variable to hold the k-th smallest element
        int cnt = 0; // Counter for the number of nodes processed
        bool found = inorder(root, cnt, K, ksmall); // Search for the k-th smallest
        return found ? ksmall : -1; // Return ksmall if found, else return -1
    }
    bool inorder(Node* root, int &cnt, int K, int &ksmall) {
        if (!root) return false; // Base case: if the tree is empty
        
        // Traverse the left subtree
        if (inorder(root->left, cnt, K, ksmall)) return true; // Check if k-th is found
        
        // Increment the count of processed nodes
        cnt++;
        
        // If the current count matches K, update ksmall
        if (cnt == K) {
            ksmall = root->data; // Store the k-th smallest value
            return true; // Indicate that we found the k-th smallest
        }
        
        // Traverse the right subtree
        return inorder(root->right, cnt, K, ksmall); // Continue searching
    }
};