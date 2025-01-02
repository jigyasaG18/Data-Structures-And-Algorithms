Minimum time taken to BURN the Binary Tree from a Node
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.

Examples : 

Input: root[] = [1,2,3,4,5,N,6,N,N,7,8,N,9,N,N,N,N,N,10],  target = 8
Output: 7
Explanation: If leaf with the value 8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.

Input: root[] = [1, 2, 3, 4, 5, N, 7, 8, N, 10], target = 10
Output: 5
Explanation: 
- After 1 sec: Node 5 catches fire.
- After 2 sec: Node 2 catches fire.
- After 3 sec: Nodes 1 and 4 catch fire.
- After 4 sec: Node 3 catches fire.
- After 5 sec: Node 7 catches fire.
Total time taken to burn the entire tree: 5 seconds.

Input: root[] = [1, 2, 3, 4, 5, 6, N, N, N, N, N, 7, 8], target = 4
Output: 4
Explanation: 
If the node with the value 4 is set on fire:
- After 1 sec: Node 2 catches fire.
- After 2 sec: Nodes 1 and 5 catch fire.
- After 3 sec: Node 3 catches fire.
- After 4 sec: Nodes 6, 7, and 8 catch fire.
Total time taken to burn the entire tree: 4 seconds.

// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  Node* find(Node* root, unordered_map<Node*,Node*> &parenttrack, int target){
      Node* tnode=NULL;
      queue<Node*>q;
      q.push(root);
      while(!q.empty()){
          Node* curr=q.front();
          q.pop();
          if (curr->data == target) {
                tnode = curr;
            }
          if(curr->left) {
              parenttrack[curr->left]=curr;
              q.push(curr->left);
          }
          if(curr->right){
              parenttrack[curr->right]=curr;
              q.push(curr->right);
          }
      }
      return tnode;
  }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*> parenttrack;
        Node* tnode=find(root,parenttrack,target);
        int maxtime=0;
        unordered_map<Node*,bool>visited;
        queue<pair<Node*,int>>q;
        q.push({tnode,0});
        visited[tnode]=true;
        while(!q.empty()){
            Node* curr=q.front().first;
            int timetaken=q.front().second;
            q.pop();
            maxtime=max(maxtime,timetaken);
    //Check left child
    if(curr->left && !visited[curr->left]){
        q.push({curr->left,timetaken+1});
        visited[curr->left]=true;
    }
    //Check right child
    if(curr->right && !visited[curr->right]){
        q.push({curr->right,timetaken+1});
        visited[curr->right]=true;
    }
    //Check parent node
    if(parenttrack[curr] && !visited[parenttrack[curr]]){
        q.push({parenttrack[curr],timetaken+1});
        visited[parenttrack[curr]]=true;
    }
        }
        return maxtime;
    }
};