Inorder Successor and Inorder Predecessor in BST

Inorder Successor in BST :-
Given a BST, and a reference to a Node k in the BST. Find the Inorder Successor of the given node in the BST. If there is no successor, return -1. 
Examples :
Input: root = [2, 1, 3], k = 2
      2
    /   \
   1     3
Output: 3 
Explanation: Inorder traversal : 1 2 3 Hence, inorder successor of 2 is 3.

Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 8
             20
            /   \
           8     22
          / \
         4   12
            /  \
           10   14
Output: 10
Explanation: Inorder traversal: 4 8 10 12 14 20 22. Hence, successor of 8 is 10.

Input: root = [2, 1, 3], k = 3
      2
    /   \
   1     3
Output: -1 
Explanation: Inorder traversal : 1 2 3 Hence, inorder successor of 3 is null.

class Solution {
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
        if (root == NULL || x == NULL) return -1;
        Node *successor = NULL;
        while (root != NULL)
        {
            if (root->data <= x->data)
            root = root->right;
            else // root->data > x->data
            {
                successor = root;
                root = root->left;
            }
        }
        if (successor == NULL) return -1;
        else return successor->data;
    }
};

Inorder Predecessor:-

class Solution {
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderPredecessor(Node *root, Node *x) {
        // Your code here
        if (root == NULL || x == NULL) return -1;
        Node *successor = NULL;
        while (root != NULL)
        {
            if (root->data <= x->data){
             predecessor = root;
            root = root->right;
            }
            else // root->data > x->data
            {
                root = root->left;
            }
        }
        if (predecessor == NULL) return -1;
        else return predecessor->data;
    }
};

Inorder Successor and Inorder Predecessor in BST:-

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
          if(root == NULL) return;
          if(key < root->key)
        {
            suc = root;
            findPreSuc(root->left, pre, suc,key);
        }
        else if(key > root->key)
        {
            pre = root;
            findPreSuc(root->right, pre, suc,key);
        }
        else //key==root->key
        {
            if(root -> left != NULL)
            {
                Node *temp = root->left;
                while(temp->right != NULL)
                {
                    temp = temp->right;
                }
                pre = temp;
            }
            if(root -> right != NULL)
            {
                Node *temp = root->right;
                while(temp->left != NULL)
                {
                    temp = temp->left;
                }
                suc = temp;
            }
        }
    }
};