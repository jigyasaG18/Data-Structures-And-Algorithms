Convert Sorted List to Binary Search Tree
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:
Input: head = []
Output: []

class Solution {
public:
TreeNode* convert(ListNode* start, ListNode* end){
    if(start==end) return nullptr;
    ListNode* slow=start;
    ListNode* fast=start;
    while(fast!=end && fast->next!=end){
        slow=slow->next;
        fast=fast->next->next;
    }
    TreeNode* head=new TreeNode(slow->val);
    head->left=convert(start,slow);
    head->right=convert(slow->next,end);
    return head;
}
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr) return nullptr;
        return convert(head,nullptr);
    }
};