Middle of a Linked List
Given the head of a linked list, the task is to find the middle. For example, the middle of 1-> 2->3->4->5 is 3. If there are two middle nodes (even count), return the second middle. For example, middle of 1->2->3->4->5->6 is 4.

Examples:
Input: Linked list: 1->2->3->4->5
Output: 3
Explanation: The given linked list is 1->2->3->4->5 and its middle is 3.

Input: Linked list: 2->4->6->7->5->1
Output: 7 
Explanation: The given linked list is 2->4->6->7->5->1 and its middle is 7.

1st Way:- Brute Force Approach
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    int mid = count / 2 + 1;
    temp = head; //reset the temp again to head since we need to traverse from beginning otherwise wrong answer will be generated
    while (temp != NULL) {
        mid = mid - 1;
        if (mid == 0){
            break;
        }
        temp = temp->next;
    }
    return temp->data;
    }
};

2nd Way:- Optimal Approach
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
};