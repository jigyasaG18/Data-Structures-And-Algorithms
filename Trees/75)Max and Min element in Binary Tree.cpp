Max and Min element in Binary Tree
Given a Binary Tree, find maximum and minimum elements in it.

Example:
Input: 
           6
        / \
       5   8
      /
     2
Output: 8 2
Explanation: The maximum and minimum element in this binary tree is 8 and 2 respectively.

class Solution
{
public:
    int findMax(Node *root)
    {
        //code here
        if(!root) return INT_MIN;
        int maxi=INT_MIN;
        int left_val=findMax(root->left);
        int right_val=findMax(root->right);
        maxi=max(root->data,max(left_val,right_val));
        return maxi;
    }
    int findMin(Node *root)
    {
        //code here
        if(!root) return INT_MAX;
        int mini=INT_MAX;
        int left_val=findMin(root->left);
        int right_val=findMin(root->right);
        mini=min(root->data,min(left_val,right_val));
        return mini;
    }
};