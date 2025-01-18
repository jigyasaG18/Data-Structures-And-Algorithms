Reverse a Linked List
Given the head of a linked list, the task is to reverse this list and return the reversed head.

Examples:
Input: head: 1 -> 2 -> 3 -> 4 -> NULL
Output: head: 4 -> 3 -> 2 -> 1 -> NULL

Input: head: 2 -> 7 -> 10 -> 9 -> 8 -> NULL
Output: head: 8 -> 9 -> 10 -> 7 -> 2 -> NULL

Input: head: 10 -> NULL
Output: 10 -> NULL

1st Way:- Iterative
class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
         if (head == NULL || head->next == NULL) {
        return head;
    }
        Node* temp=head;
        Node* prev= NULL;
        while(temp!=NULL){
            Node* front=temp->next;
            temp->next=prev;
            
            prev=temp;
            temp=front;
        }
        return prev;
    }
};

2nd Way:- Recursive
class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newHead = reverseList(head->next);
    Node* front = head->next;
    
    front->next = head;
    head->next = NULL;
    
    return newHead;
    }
};