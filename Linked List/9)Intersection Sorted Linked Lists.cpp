Intersection Sorted Linked Lists
Given that two linked lists are sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made without changing the original lists.
Note: The elements of the linked list are not necessarily distinct.

Examples:
Input: LinkedList1 = 1->2->3->4->6, LinkedList2 = 2->4->6->8
Output: 2->4->6
Explanation: For the given two linked list, 2, 4 and 6 are the elements in the intersection.

Input: LinkedList1 = 10->20->40->50, LinkedList2 = 15->40
Output: 40

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code goes here.
        Node* dnode=new Node(-1);
        Node* temp=dnode;
        while(head1!=NULL && head2!=NULL){
            if(head1->data == head2->data){
                dnode->next=head1;
                dnode=head1;
                head1=head1->next;
                head2=head2->next;
            }
            else if(head1->data > head2->data){
                head2 = head2->next;
            }
            else{
                head1 = head1->next;
            }
        }
        dnode->next=NULL;
        return temp->next;
    }
};