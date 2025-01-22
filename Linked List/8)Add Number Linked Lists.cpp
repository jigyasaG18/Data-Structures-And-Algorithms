Add Number Linked Lists
Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of the linked list representing the sum of these two numbers.
For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.
Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Examples:
Input: num1 = 4 - > 5, num2 = 3 -> 4 -> 5
Output:  3 -> 9 -> 0
Explanation: Given numbers are 45 and 345. There sum is 390.

Input: num1 = 0 -> 0 -> 6 -> 3, num2 = 0 -> 7 
Output: 7 -> 0 
Explanation: Given numbers are 63 and 7. There sum is 70.

class Solution {
  public:
  Node* reverseLL(Node* head){
    Node *curr = head, *prev = nullptr, *next;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        while(num1->next!=NULL && num1->data==0){

        num1=num1->next;

        }

        while(num2->next!=NULL && num2->data==0){

        num2=num2->next;

       }
         num1=reverseLL(num1);
    num2=reverseLL(num2);
        Node* t1=num1;
        Node* t2=num2;
        Node* dnode=new Node(-1);
        Node* curr=dnode;
        int carry=0;
        while(t1!=NULL || t2!=NULL){
             int sum=carry;
            if(t1) sum=sum+t1->data;
            if(t2) sum=sum+t2->data;
            
            Node* newnode=new Node(sum%10);
            carry=sum/10;
            curr->next=newnode;
            curr=curr->next;
            
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }
        if(carry){
            Node* nnode=new Node(carry);
            curr->next=nnode;
        }
        
        return reverseLL(dnode->next);
    }
};

2nd Way of Question:-
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummynode = new ListNode(-1);
        ListNode* curr = dummynode;
        int carry = 0;

        while (temp1 != NULL || temp2 != NULL) {
            int sum = carry;
            if (temp1)
                sum = sum + temp1->val;
            if (temp2)
                sum = sum + temp2->val;

            ListNode* newnode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newnode;
            curr = curr->next;

            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }

        if(carry){
           ListNode* newnode=new ListNode(carry);
           curr->next=newnode;
        }
        return dummynode->next;
    }
};