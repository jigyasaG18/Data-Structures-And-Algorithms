Remove loop in Linked List
Given the head of a linked list that may contain a loop.  A loop means that the last node of the linked list is connected back to a node in the same list. The task is to remove the loop from the linked list (if it exists).
Custom Input format:
A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.
The generated output will be true if there is no loop in list and other nodes in the list remain unchanged, otherwise, false.

Examples:
Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation: A loop is present in the list, and it is removed.

Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true
Explanation: The Linked list does not contains any loop. 

Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: A loop is present in the list, and it is removed.

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        Node *slow = head, *fast = head;

        // Step 1: Detect loop using Floyd's cycle detection
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find the starting point of the loop
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                // Step 3: Find the last node in the loop
                while (fast->next != slow) {
                    fast = fast->next;
                }
                // Break the loop
                fast->next = NULL;
            }
        }
    }
};