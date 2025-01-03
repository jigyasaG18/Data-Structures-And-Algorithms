Single Valued Subtree
Given a binary tree, count the number of Single Valued Subtrees. A Single Valued Subtree is one in which all the nodes have same value. 
Example 1
Input :
              5
             / \
            1   5
           / \   \
          5   5   5
Output : 4
Explanation : There are 4 subtrees with single values. Three leaf nodes and the subtree whose root is the right child of the root. 

Example 2:
Input:
              5
             / \
            4   5
           / \   \
          4   4   5   
Output: 5
Explanation: There are five subtrees with single values.

//User function Template for C++

/* Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution
{
    public:
     bool isSingleValued(Node* root, int &cnt) {
        if (!root) return true; // An empty node is considered single-valued
        
        // Check left and right children
        bool leftSingle = isSingleValued(root->left, cnt);
        bool rightSingle = isSingleValued(root->right, cnt);
        
        // If any of the child subtrees is not single-valued, return false
        if (!leftSingle || !rightSingle) {
            return false;
        }
        
        // If there is a left child, check that its value matches
        if (root->left && root->left->data != root->data) {
            return false;
        }
        
        // If there is a right child, check that its value matches
        if (root->right && root->right->data != root->data) {
            return false;
        }
        
        // If the current node matches its children's values,
        // increment the single-valued subtree count
        cnt++;
        
        // Return true since this subtree is single-valued
        return true;
    }

    int singlevalued(Node *root)
    {
        //code here
          int cnt = 0; // Initialize count of single-valued subtrees
        isSingleValued(root, cnt); // Call the helper function
        return cnt; // Return the count
    }
    
};