Serialize and Deserialize Binary Tree
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:
Input: root = []
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         if (!root) return "#";  // Use only '#' for NULL nodes
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == NULL) {
                s.append("#,");  // Node is NULL
            } else {
                s.append(to_string(curr->val) + ",");  // Node exists
            }
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         if (data == "#") return NULL;  // Empty tree special case
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // Get left child
            getline(s, str, ',');
            if (str == "#") {
                curr->left = NULL;
            } else {
                TreeNode* lnode = new TreeNode(stoi(str));
                curr->left = lnode;
                q.push(lnode);
            }

            // Get right child
            getline(s, str, ',');
            if (str == "#") {
                curr->right = NULL;
            } else {
                TreeNode* rnode = new TreeNode(stoi(str));
                curr->right = rnode;
                q.push(rnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root)); 

2nd Way:-
class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> ans;
        if(!root) return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            
            if(curr==NULL) ans.push_back(-1);
            else ans.push_back(curr->data);
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        // Your code here
          if (arr.empty() || arr[0] == -1) return NULL;  // Check for the case of an empty tree
        
        Node* root = new Node(arr[0]); // Create the root node
        queue<Node*> q;
        q.push(root);
        
        int i = 1; // Start from the second element in the array
        
        while (!q.empty() && i < arr.size()) {
            Node* curr = q.front();
            q.pop();
            
            // Deserialize left child
            if (arr[i] == -1) {
                curr->left = NULL;
            } else {
                curr->left = new Node(arr[i]);
                q.push(curr->left);
            }
            i++;
            
            // Deserialize right child
            if (i < arr.size()) {
                if (arr[i] == -1) {
                    curr->right = NULL;
                } else {
                    curr->right = new Node(arr[i]);
                    q.push(curr->right);
                }
                i++;
            }
        }
        
        return root;
    }
};