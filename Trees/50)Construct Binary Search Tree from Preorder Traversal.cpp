Construct Binary Search Tree from Preorder Traversal
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Example 1:
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Example 2:
Input: preorder = [1,3]
Output: [1,null,3]

1st Way:- Recursive
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
    TreeNode* build(vector<int>& preorder, int &i, int bound) {
        if(i==preorder.size() || preorder[i]>bound) return nullptr;
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,bound);
        return root;
    }
};

2nd Way:- Recursive
class Solution {
  public:
  int i=0;
    int canRepresentBST(int arr[], int N) {
        // code here
         int mini=INT_MIN;
        int maxi=INT_MAX;
        solve(arr,N,mini,maxi);
        if(i>=N){
            return 1;
        }
        return 0;
    }
       void solve(int arr[], int& N,int mini,int maxi){
        if(i>=N){
            return;
        }
        if(arr[i]<mini || arr[i]>maxi){
            return ;
        }
        int curr=arr[i];
        i++;
        solve(arr,N,mini,curr);
        solve(arr,N,curr,maxi);
        return;
        
    }
};

3rd Way:- Iterative
class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        // code here
        stack<int>st;
          int root = -1;
       for(int i=0;i<N;i++) {
          if(arr[i]<root) return 0;
           while(!st.empty() && arr[i]>st.top()) {
               root = st.top();
               st.pop();
           }
           st.push(arr[i]);
       }
       return 1;
    }
};