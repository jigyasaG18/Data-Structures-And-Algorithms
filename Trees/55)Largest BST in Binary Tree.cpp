Largest BST in Binary Tree
You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.
Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

Examples :
Input: root = [5, 2, 4, 1, 3]
Output: 3

Input: root = [6, 7, 3, N, 2, 2, 4]
Output: 3

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class NodeValue{
    public:
    int maxnode;
    int minnode;
    int maxsize;
    NodeValue(int minnode, int maxnode, int maxsize){
    this ->   maxnode = maxnode;
    this ->  minnode  = minnode;
    this -> maxsize   = maxsize;
    }
};
class Solution{
    private:
    NodeValue largestBSTSubtree(Node* root){
        if(!root) return NodeValue(INT_MAX,INT_MIN,0);
        auto left=largestBSTSubtree(root->left);
        auto right=largestBSTSubtree(root->right);
        if(left.maxnode<root->data && root->data<right.minnode){
            return NodeValue(min(root->data,left.minnode),max(root->data,right
            .maxnode),(left.maxsize+right.maxsize+1));
        }
        else
        return NodeValue(INT_MIN,INT_MAX,max(left.maxsize,right.maxsize));
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	return largestBSTSubtree(root).maxsize;
    }
};