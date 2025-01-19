Rotate a Linked List
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

class Solution {
public:
    ListNode* findnthnode(ListNode* temp, int k){
        int cnt=1;
        while(temp!=nullptr){
            if(cnt==k) return temp;

            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0) return head;
        ListNode* tail=head;
         int len=1;
        while(tail->next!=nullptr && tail!=nullptr){
            len++;
            tail=tail->next;
        }
        if(k%len==0) return head;

        k=k%len;
        tail->next=head;
        ListNode* newnode= findnthnode(head, len-k);
        head=newnode->next;
        newnode->next=nullptr;

        return head;
    }
};

Given the head of a singly linked list, your task is to left rotate the linked list k times.

Examples:
Input: head = 10 -> 20 -> 30 -> 40 -> 50, k = 4
Output: 50 -> 10 -> 20 -> 30 -> 40
Explanation:
Rotate 1: 20 -> 30 -> 40 -> 50 -> 10
Rotate 2: 30 -> 40 -> 50 -> 10 -> 20
Rotate 3: 40 -> 50 -> 10 -> 20 -> 30
Rotate 4: 50 -> 10 -> 20 -> 30 -> 40

Input: head = 10 -> 20 -> 30 -> 40 , k = 6
Output: 30 -> 40 -> 10 -> 20 

class Solution {
  public:
  Node* findnthnode(Node* temp, int k){
      int cnt=1;
      while(temp!=NULL){
          if(cnt==k) return temp;
          cnt++;
      temp=temp->next;
      }
      return temp;
  }
    Node* rotate(Node* head, int k) {
        // Your code here
        if(head==NULL || k==0) return head;
        int len=1;
        Node* tail=head;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        if(k%len==0) return head;
        k=k%len;
        tail->next=head;
        Node* newnode=findnthnode(head,k);
        head=newnode->next;
        newnode->next=NULL;
        return head;
    }
};
