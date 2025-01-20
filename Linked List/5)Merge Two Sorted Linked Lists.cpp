Merge Two Sorted Linked Lists
Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the sorted merged list.

Examples:
Input: head1 = 5 -> 10 -> 15 -> 40, head2 = 2 -> 3 -> 20
Output: 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40

Input: head1 = 1 -> 1, head2 = 2 -> 4
Output: 1 -> 1 -> 2 -> 4

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* t1=head1;
        Node* t2=head2;
        Node* dnode=new Node(-1);
        Node* temp=dnode;
        while(t1!=NULL && t2!=NULL){
            if(t1->data<t2->data){
                temp->next=t1;
                temp=t1;
                t1=t1->next;
            }
            else{
                temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }
        if(t1) temp->next=t1;
        else temp->next=t2;
        
        return dnode->next;
    }
};