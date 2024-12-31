Preorder, Inorder, and Postorder Traversal in one Traversal
                            
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to get the Preorder,
// Inorder and Postorder traversal
// Of Binary Tree in One traversal
vector<vector<int>> preInPostTraversal(Node* root) {
    // Vectors to store traversals
    vector<int> pre, in, post;

    // If the tree is empty,
    // return empty traversals
    if (root == NULL) {
        return;
    }

    // Stack to maintain nodes
    // and their traversal state
    stack<pair<Node*, int>> st;

    // Start with the root node
    // and state 1 (preorder)
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of preorder
        if (it.second == 1) {
            // Store the node's data
            // in the preorder traversal
            pre.push_back(it.first->data);
            // Move to state 2
            // (inorder) for this node
            it.second ++; //it.second gets updated from 1 to 2
            // Push the updated state
            // back onto the stack
            st.push(it); 

            // Push left child onto
            // the stack for processing
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }

        // this is a part of inorder
        else if (it.second == 2) {
            // Store the node's data
            // in the inorder traversal
            in.push_back(it.first->data);
            // Move to state 3
            // (postorder) for this node
            it.second ++; //it.second gets updated from 2 to 3
            // Push the updated state
            // back onto the stack
            st.push(it); 

            // Push right child onto
            // the stack for processing
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }

        // this is part of postorder 
        else {  //here it.second value is 3
            // Store the node's data
            // in the postorder traversal
            post.push_back(it.first->data);
        }
    }

    // Returning the traversals
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}
