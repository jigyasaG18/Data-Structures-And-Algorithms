Merge K Sorted Linked Lists
Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list, then return the head of the merged linked list.

Examples:

Input: arr[] = [1 -> 2 -> 3, 4 -> 5, 5 -> 6, 7 -> 8]
Output: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 7 -> 8
Explanation:
The arr[] has 4 sorted linked list of size 3, 2, 2, 2.
1st list: 1 -> 2-> 3
2nd list: 4 -> 5
3rd list: 5 -> 6
4th list: 7 -> 8
The merged list will be: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 7 -> 8
 
Input: arr[] = [1 -> 3, 8, 4 -> 5 -> 6]
Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
Explanation:
The arr[] has 3 sorted linked list of size 2, 3, 1.
1st list: 1 -> 3
2nd list: 8
3rd list: 4 -> 5 -> 6
The merged list will be: 1 -> 3 -> 4 -> 5 -> 6 -> 8

class Solution {
    public:
      Node* mergeKLists(vector<Node*>& arr) {
          // Your code here
           // store all elements in a vector
          vector<int> v;
          for(int i=0;i<arr.size();i++)
          {
              Node*p=arr[i];
              while(p!=NULL)
              {
                  v.push_back(p->data);
                  p=p->next;
              }
          }
            
          // sort the vector
          sort(v.begin(),v.end());
          // create the linked list
          Node*dnode=new Node(-1);
          Node*temp=dnode;
          for(int i=0;i<v.size();i++)
          {
              Node*newnode=new Node(v[i]);
              temp->next=newnode;
              temp=newnode;
          }
          return dnode->next;
      }
  };