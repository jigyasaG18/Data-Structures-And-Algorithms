Boundary Traversal of Binary Tree
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 
Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.
Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.
Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Examples:
Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N] 
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: [1, 2, 4, 8, 9, 6, 7, 3]

Input: root[] = [1, 2, N, 4, 9, 6, 5, N, 3, N, N, N, N 7, 8] 
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: [1, 2, 4, 6, 5, 7, 8]
Explanation:
As the root doesn't have a right subtree, the right boundary is not included in the traversal.

Input: root[] = [1, N, 2, N, 3, N, 4, N, N] 
    1
     \
      2
       \
        3
         \
          4

Output: [1, 4, 3, 2]
Explanation:
Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]

class Solution {
  public:
  // Function to check if a node is a leaf
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }

    void left(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    void right(Node* root, vector<int>& res) {
        Node* curr = root->right; // Initialize curr properly
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->data);
            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        // Push values from temp in reverse order
        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

    void leaves(Node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) leaves(root->left, res);
        if (root->right) leaves(root->right, res);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        left(root, res);
        leaves(root, res);
        right(root, res);
        return res;
    }
};