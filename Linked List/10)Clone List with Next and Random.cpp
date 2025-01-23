Clone List with Next and Random
You are given a special linked list with n nodes where each node has two pointers a next pointer that points to the next node of the singly linked list, and a random pointer that points to the random node of the linked list.
Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list state. None of the pointers in the new list should point to nodes in the original list.
Return the head of the copied linked list.
NOTE : Original linked list should remain unchanged.

Examples:
Input: head = [[1, 3], [3, 3], [5, NULL], [9, 3]] 
Output: head = [[1, 3], [3, 3], [5, NULL], [9, 3]] 
Explanation: 
Node 1 points to Node 2 as its NEXT and Node 3 as its RANDOM.
Node 2 points to Node 3 as its NEXT and Node 3 as its RANDOM.
Node 3 points to Node 4 as its NEXT and NULL as its RANDOM.
Node 4 points to NULL as its NEXT and Node 3 as its RANDOM.

Input: head = [[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]
Output: head = [[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]
Explanation: 
Node 1 points to Node 2 as its NEXT and Node 3 as its RANDOM.
Node 2 points to Node 3 as its NEXT and Node 1 as its RANDOM.
Node 3 points to Node 4 as its NEXT and Node 5 as its RANDOM.
Node 4 points to Node 5 as its NEXT and Node 3 as its RANDOM.
Node 5 points to NULL as its NEXT and Node 2 as its RANDOM.

Input: head = [[7, NULL], [7, NULL]]
Output: head = [[7, NULL], [7, NULL]]
Explanation: 
Node 1 points to Node 2 as its NEXT and NULL as its RANDOM.
Node 2 points to NULL as its NEXT and NULL as its RANDOM.

class Solution {
  public:
  Node* insertcopy(Node* head){
      Node* temp= head;
      while(temp!=NULL){
      Node* copynode= new Node(temp->data);
      copynode->next=temp->next;
      temp->next=copynode;
      temp=temp->next->next;
      }
      return temp;
  }
  Node* connectrandom(Node* head){
      Node* temp= head;
      while(temp!=NULL){
          Node* copynode=temp->next;
          if(temp->random) copynode->random=temp->random->next;
          else copynode->random=NULL;
          
          temp=temp->next->next;
      }
      return temp;
  }
  Node* connectnext(Node* head){
      Node* dnode= new Node(-1);
      Node* res=dnode;
      Node* temp=head;
      while(temp!=NULL){
          res->next=temp->next;
          temp->next=temp->next->next;
          res=res->next;
          temp=temp->next;
      }
      return dnode->next;
  }
    Node *cloneLinkedList(Node *head) {
        // Write your code here
         insertcopy(head);
        connectrandom(head);
        return connectnext(head);
    }
};