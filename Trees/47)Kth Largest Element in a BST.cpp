Kth largest Element in a BST
Given a Binary Search Tree. Your task is to complete the function which will return the kth largest element without doing any modification in the Binary Search Tree.
Examples:
Input:
      4
    /   \
   2     9
k = 2 
Output: 4
Explanation: 2nd Largest element in BST is 4

Input:
       9
        \ 
          10
k = 1
Output: 10
Explanation: 1st Largest element in BST is 10

Input:
      4
    /   \
   2     9
k = 3 
Output: 2
Explanation: 3rd Largest element in BST is 2

class Solution {
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
        int  kLargest = INT_MIN;
        int counter = 0; 
        // Find Kth largest element
        // (perform reverse inorder traversal)
        reverseInorder(root, counter, k, kLargest);
         return kLargest;
    }
    // Helper function to perform reverse inorder
    // traversal to find Kth largest element
    void reverseInorder(Node* root, int& counter, int &k, int& kLargest) {
        if (!root || counter >= k) return;

        // Traverse right subtree
        reverseInorder(root->right, counter, k, kLargest);

        // Increment counter after
        // visiting right subtree
        counter++;

        // Check if current node
        // is the Kth largest
        if (counter == k) {
            kLargest = root->data;
            return;
        }

        // Traverse left subtree if
        // Kth largest is not found yet
        reverseInorder(root->left, counter, k, kLargest);
    }

};