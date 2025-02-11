K Sum Paths
Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).
Examples:
Input: k = 3
   1
  /  \
2     3
Output: 2
Explanation:
Path 1 : 1 -> 2 (Sum = 3)
Path 2 : 3 (Sum = 3)

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    public:
    void solve(Node* root, unordered_map<int, int> &mpp, int k, int &cnt, int curr) {
      if (root == NULL) return;
      
      // Accumulate the current sum with the value of the current node
      curr += root->data;
  
      // Check if there is a stored prefix sum that when subtracted from the current sum equals k
      if (mpp.find(curr - k) != mpp.end()) {
          cnt += mpp[curr - k];  // Increment count by the number of times this prefix sum has occurred
      }
      
      // If current sum equals k, we have found a complete path from the root to the current node
      if (curr == k) cnt++;
      
      // Store the current sum in the map
      mpp[curr]++;
      
      // Explore the left and right children
      solve(root->left, mpp, k, cnt, curr);
      solve(root->right, mpp, k, cnt, curr);
      
      // Before backtracking, remove/decrement the current sum from the map
      mpp[curr]--; 
  }
      int sumK(Node *root, int k) {
          // code here
      unordered_map<int, int> mpp; // To store the prefix sum frequencies
      int cnt = 0;
      solve(root, mpp, k, cnt, 0); // Initialize the recursive function
      return cnt; // Return the count of paths that sum to k
  
      }
  };