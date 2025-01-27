Kth from End of Linked List
Given the head of a linked list and the number k, Your task is to find the kth node from the end. If k is more than the number of nodes, then the output should be -1.

Examples
Input: LinkedList: 1->2->3->4->5->6->7->8->9, k = 2
Output: 8
Explanation: The given linked list is 1->2->3->4->5->6->7->8->9. The 2nd node from end is 8.

Input: LinkedList: 10->5->100->5, k = 5
Output: -1
Explanation: The given linked list is 10->5->100->5. Since 'k' is more than the number of nodes, the output is -1.

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        if(head == NULL) return -1;
       Node *slow = head;
       Node *fast = head;
       
       for(int i = 0 ; i < k; i ++) {
           if (fast == NULL) { //k larger than number of nodes
               return -1;
           }
           fast = fast->next;
       }
       
       while (fast != nullptr) {
           fast = fast->next;
           slow = slow->next;
       }
       
       return slow->data;
    }
};