Is Binary Tree Heap
You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.
A binary tree is considered a max-heap if it satisfies the following conditions:
Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.

Examples:
Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]
Output: true
Explanation: The tree is complete and satisfies the max-heap property.

Input: root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4] 
Output: false
Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.

class Solution {
    public:
    bool func(Node* root){
        queue<Node*>q;
        q.push(root);
        while(q.size()){
            vector<int>temp;
            int size=q.size();
            while(size--){
                auto ele=q.front();
                q.pop();
                if(ele->left){
                    if(ele->data<ele->left->data) return false;
                    q.push(ele->left);
                    temp.push_back(ele->left->data);
                }
                else temp.push_back(-1);
                
                if(ele->right){
                    if(ele->data<ele->right->data) return false;
                    q.push(ele->right);
                    temp.push_back(ele->right->data);
                }
                else temp.push_back(-1);
            } 
            bool isnull=false;
            for(auto it : temp){
                if(it==-1) isnull=true;
                if(isnull==true && it!=-1) return false;
            }
        }
         return true;
    }
      bool isHeap(Node* tree) {
          // code here
          if(!func(tree)) return false;
          return true;
      }
  };