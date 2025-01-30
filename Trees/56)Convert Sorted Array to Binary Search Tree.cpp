Convert Sorted Array to Binary Search Tree
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

Input: nums = [1, 2, 3, 4]
Output: true
Explanation: The preorder traversal of the following BST formed is [2, 1, 3, 4]:
           2
         /   \
        1     3
               \
                4

Input: nums = [1, 2, 3, 4, 5, 6, 7]
Ouput: true
Explanation: The preorder traversal of the following BST formed is [4, 2, 1, 3, 6, 5, 7]:
        4
       / \
      2   6
     /\  / \
    1 3  5 7   

class Solution {
public:
TreeNode* helper(vector<int>& nums, int left , int right){
    if(left > right) return nullptr;
    int mid = left + (right - left)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root -> left = helper(nums,left,mid-1);
    root -> right = helper(nums,mid+1,right);
    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums , 0 , nums.size()-1);
    }
};