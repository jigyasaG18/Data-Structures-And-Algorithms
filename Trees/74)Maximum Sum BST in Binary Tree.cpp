Maximum Sum BST in Binary Tree
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
Example 1:
Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

Example 2:
Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.

Example 3:
Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.

class Node{
    public: int maxnode;
    int minnode;
    int maxsum;
 Node(int maxnode, int minnode, int maxsum){
    this -> maxnode = maxnode;
    this -> minnode = minnode;
    this -> maxsum = maxsum;
}
};
class Solution {
public:
int max_sum=INT_MIN;
Node func(TreeNode* root){
    if(!root) return Node(INT_MIN,INT_MAX,0);
    auto left = func(root->left);
    auto right = func(root->right);
    if(left.maxnode<root->val && root->val<right.minnode){ //It is a valid BST
    max_sum=max(max_sum,root->val+left.maxsum+right.maxsum);

    return Node(max(root->val,right.maxnode),min(root->val,left.minnode),root->val+left.maxsum+right.maxsum);
}
else{
return Node(INT_MAX,INT_MIN,max(left.maxsum,right.maxsum));
}
}
    int maxSumBST(TreeNode* root) {
        func(root);
        return (max_sum<0) ? 0 : max_sum;
    }
};