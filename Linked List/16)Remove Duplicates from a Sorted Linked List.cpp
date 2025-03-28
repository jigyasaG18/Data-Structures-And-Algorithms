Remove Duplicates from a Sorted Linked List
Given a singly linked list. The task is to remove duplicates (nodes with duplicate values) from the given list (if it exists).
Note: Try not to use extra space. The nodes are arranged in a sorted way.

Examples:
Input:
LinkedList: 2->2->4->5
Output: 2 -> 4 -> 5
Explanation: In the given linked list 2 -> 2 -> 4 -> 5, only 2 occurs more than 1 time. So we need to remove it once.

Input:
LinkedList: 2->2->2->2->2
Output: 2
Explanation: In the given linked list  2 -> 2 -> 2 -> 2, 2 is the only element and is repeated 5 times. So we need to remove any four 2.

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        // code here
        if(head== NULL || head->next==NULL) return head;
        Node* temp = head;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->data == temp->next->data){
                temp->next=temp->next->next;
            }
            else{
            temp=temp->next;
            }
        }
        return head;
    }
};