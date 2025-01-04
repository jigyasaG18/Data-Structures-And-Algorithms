Binary Search Trees
Given an array of integers arr[] representing inorder traversal of elements of a binary tree. Return true if the given inorder traversal can be of a valid Binary Search Tree.
Note - In a valid Binary Search Tree all keys are unique.
Examples :

Input: arr[] = [8, 14, 45, 64, 100]
Output: True

Input: arr[] = [5, 6, 1, 8, 7]
Output: False

class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1]){
             return false;
        }
        }
        return true;
    
//The inorder traversal of binary search tree comes in ascending order so we are checking whether the given input array elements are arranged in ascending order. 
//If then return true else return false.
    }
};

Search a node in BST
Given a Binary Search Tree and a node value X, find if the node with value X is present in the BST or not.

Example 1:
Input:         2
                \
                 81 
               /    \ 
             42      87 
              \       \ 
               66      90 
              / 
            45
X = 87
Output: 1
Explanation: As 87 is present in the given nodes , so the output will be 1.

Example 2:
Input:      6
             \ 
              8 
             / \ 
            7   9
X = 11
Output: 0
Explanation: As 11 is not present in the given nodes , so the output will be 0.

bool search(Node* root, int x) {
    // Your code here
    Node* node=root;
    while(node!=NULL){
        if(node->data==x) return 1;
        if(node->data>x){
            node=node->left;
        } 
        else 
        {node=node->right;
        }
    }
    return 0;
}