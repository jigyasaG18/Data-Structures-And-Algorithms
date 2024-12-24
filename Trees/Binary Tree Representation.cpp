Binary Tree Representation
You are given an array nodes. It contains 7 integers, which represents the value of nodes of the binary tree in level order traversal. You are also given a root of the tree which has a value equal to nodes[0].

Your task to construct a binary tree by creating nodes for the remaining 6 nodes.

Example:

Input: 
nodes = [1 2 3 4 5 6 7]
Output: 
         1
       /   \
     2       3
   /  \     /  \
   4  5    6   7
Explanation: 
The 7 node binary tree is represented above.

void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
         int n = vec.size();
        queue<node*> q;
        q.push(root0);
        
        for(int i=0; i<n/2; i++) {
            struct node* temp = q.front();
            q.pop();
            
            int left = 2*i+1;
            int right = 2*i+2;
            
            if(left < n) temp->left = newNode(vec[left]);
            if(right < n) temp->right = newNode(vec[right]);
            
            q.push(temp->left);
            q.push(temp->right);
        }
    }

