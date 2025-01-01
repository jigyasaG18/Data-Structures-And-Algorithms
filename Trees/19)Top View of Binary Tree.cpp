Top View of Binary Tree
You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
Note: 
Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 

Examples:
Input: root[] = [1, 2, 3] 
Output: [2, 1, 3]

Input: root[] = [10, 20, 30, 40, 60, 90, 100]
 Output: [40, 20, 10, 30, 100]
Explaination: The root 10 is visible.
On the left, 40 is the leftmost node and visible, followed by 20.
On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.

Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
       1
     /   \
    2     3
     \   
      4
       \
        5
         \
          6
Output: [2, 1, 3, 6]
Explaination: Node 1 is the root and visible.
Node 2 is the left child and visible from the left side.
Node 3 is the right child and visible from the right side.
Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view. Thus, the top view is 2 1 3 6.

struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
          // Vector to store the result
        vector<int> ans;
        
        // Check if the tree is empty
        if(root == NULL){
            return ans;
        }
        
        // Map to store the top view nodes
        // based on their vertical positions
        map<int, int> mpp;
        
        // Queue for BFS traversal, each element
        // is a pair containing node 
        // and its vertical position
        queue<pair<Node*, int>> q;
        
        // Push the root node with its vertical
        // position (0) into the queue
        q.push({root, 0});
        
        // BFS traversal
        while(!q.empty()){
            // Retrieve the node and its vertical
            // position from the front of the queue
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            
            // If the vertical position is not already
            // in the map, add the node's data to the map
            if(mpp.find(line) == mpp.end()){
                mpp[line] = node->data;
            }
            
            // Process left child
            if(node->left != NULL){
                // Push the left child with a decreased
                // vertical position into the queue
                q.push({node->left, line - 1});
            }
            
            // Process right child
            if(node->right != NULL){
                // Push the right child with an increased
                // vertical position into the queue
                q.push({node->right, line + 1});
            }
        }
        
        // Transfer values from the
        // map to the result vector
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};