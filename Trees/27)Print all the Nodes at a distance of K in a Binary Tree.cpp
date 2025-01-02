Print all the Nodes at a distance of K in a Binary Tree
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
You can return the answer in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:
Input: root = [1], target = 1, k = 3
Output: []

1st Way:-
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<int,TreeNode*>mpp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();
        if(top->left){
                   mpp[top->left->val]=top;
                   q.push(top->left);
                }
         if(top->right){
                   mpp[top->right->val]=top;
                   q.push(top->right);
                }
            }   
        }
        unordered_map<int,int>visited;
        q.push(target);
        while(k-- && !q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();
                visited[top->val]=1;
                if(top->left && !visited[top->left->val]){
                    q.push(top->left);
                }
                if(top->right && !visited[top->right->val]){
                    q.push(top->right);
                }
                if (mpp[top->val] && !visited[mpp[top->val]->val] ) {
                q.push(mpp[top->val]);
            }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};

2nd Way:-
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution {

  public:
  Node* findTarget(Node* root, int target) {
    if (!root) return nullptr;
    if (root->data == target) return root;
    
    Node* left = findTarget(root->left, target);
    if (left) return left;

    return findTarget(root->right, target);
}

    vector<int> KDistanceNodes(Node* root, int target, int k) {
        // return the sorted vector of all nodes at k dist
        // return the sorted vector of all nodes at distance k
    vector<int> ans;
    unordered_map<int, Node*> parent;
    queue<Node*> q;

    // Step 1: Build the parent map
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();
            
            if (current->left) {
                parent[current->left->data] = current;
                q.push(current->left); 
            }
            if (current->right) {
                parent[current->right->data] = current;
                q.push(current->right); 
            }
        }
    }

    // Step 2: Find the target node
    Node* targetNode = findTarget(root, target);
    if (!targetNode) return ans; // If the target node is not found

    // Step 3: BFS to find all nodes at distance k
    unordered_map<int, bool> visited;
    q.push(targetNode);
    visited[targetNode->data] = true;

    while (k-- && !q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();

            if (current->left && !visited[current->left->data]) {
                visited[current->left->data] = true;
                q.push(current->left);
            }
            if (current->right && !visited[current->right->data]) {
                visited[current->right->data] = true;
                q.push(current->right);
            }
            if (parent[current->data] && !visited[parent[current->data]->data]) {
                visited[parent[current->data]->data] = true;
                q.push(parent[current->data]);
            }
        }
    }

    // Collect results
    while (!q.empty()) {
        ans.push_back(q.front()->data);
        q.pop();
    }

    // Sort the results before returning
    sort(ans.begin(), ans.end());
    return ans;
    }
};