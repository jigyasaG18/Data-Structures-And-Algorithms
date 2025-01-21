Linked List Group Reverse
Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.

Examples:
Input: head = 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4
Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5
Explanation: The first 4 elements 1, 2, 2, 4 are reversed first and then the next 4 elements 5, 6, 7, 8. Hence, the resultant linked list is 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5.

Input: head = 1 -> 2 -> 3 -> 4 -> 5, k = 3
Output: 3 -> 2 -> 1 -> 5 -> 4
Explanation: The first 3 elements 1, 2, 3 are reversed first and then left out elements 4, 5 are reversed. Hence, the resultant linked list is 3 -> 2 -> 1 -> 5 -> 4.

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if(head==NULL) return NULL;
        Node *temp=head;
        Node *prev=NULL;
        Node *next=NULL;
        int count=0;
        while(temp!=NULL and count<k)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
            count++;
        }//until here first half is reversed
        if(next!=NULL)
        {
            head->next=reverseKGroup(next,k);//next half is reversed
        }
        head=prev;
        return head;
    }
};