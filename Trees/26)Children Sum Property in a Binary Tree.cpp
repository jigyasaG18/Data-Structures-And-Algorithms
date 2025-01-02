Children Sum Property in a Binary Tree
Given a binary tree having n nodes. Check whether all of its nodes have a value equal to the sum of their child nodes. Return 1 if all the nodes in the tree satisfy the given properties, else it returns 0. For every node, the data value must be equal to the sum of the data values in the left and right children. Consider the data value 0 for a NULL child. Also, leaves are considered to follow the property.

Examples:
Input: Binary tree
       35
      /  \
     20   15
    / \   / \
   15  5 10  5

Output: 1
Explanation: Here, every node is sum of its left and right child.

Input: Binary tree
       1
     /   \
    4     3
   /  
  5    
Output: 0
Explanation: Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.

Input: Binary tree
       10
      /  \
     4    6
    / \  / \
   1   3 2  4

Output: 1
Explanation: Here, every node is a sum of its left and right child.

class Solution{
    public:
      void changeTree(Node* root) {
        // Base case: If the current node is NULL, return.
        if (root == NULL) {
            return;
        }

        // Recursively call the function for left and right children.
        changeTree(root->left);
        changeTree(root->right);

        // Calculate the sum of the values of the left and right children.
        int leftData = (root->left) ? root->left->data : 0;
        int rightData = (root->right) ? root->right->data : 0;

        // Update the current node's value to be the sum of its children's values.
        root->data = leftData + rightData;
    }

    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     // Base case: If the current node is NULL or a leaf node, it satisfies the property.
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return true;
        }

        // Calculate the sum of the values of the left and right children.
        int childSum = 0;
        if (root->left) {
            childSum += root->left->data;
        }
        if (root->right) {
            childSum += root->right->data;
        }

        // Check if the current node satisfies the sum property.
        if (root->data == childSum) {
            // Recursively check for left and right subtrees.
            return (root->data==childSum) && isSumProperty(root->left) && isSumProperty(root->right);
        }
        
        return false; // If the sum property is not satisfied, return false.    
    }
};

Dry Run:-
      10
     /  \
    5    5
   /
  5
This tree can be represented as follows:
- The root node has a value of `10`.
- The left child of the root (`5`) has one left child (`5`), and the right child of the root also has a value of `5`.

Step 1: Before calling `changeTree`
Initial Tree Node Values:
- Root (10)
- Left Child (5)
    - Left Child (5)
- Right Child (5)

Run `changeTree`
Call `changeTree(root)` where `root->data` = 10

1. Left Subtree of Root:
   - Call `changeTree(root->left)` where `root->left->data` = 5
   - Call `changeTree(root->left->left)` where `root->left->left->data` = 5 (leaf node)
   - Return from this call (no children)
   - Call `changeTree(root->left->right)` (it is NULL) → Return
   - Calculate leftData = 5 (left) + 0 (right) = 5
   - Update `root->left->data` to 5.

2. Right Subtree of Root:
   - Call `changeTree(root->right)` where `root->right->data` = 5 (leaf node)
   - Call `changeTree(root->right->left)` (it is NULL) → Return
   - Call `changeTree(root->right->right)` (it is NULL) → Return
   - Calculate leftData = 0 + 0 = 0.
   - Update `root->right->data` to 0.

3. Back to Root:
   - Calculate leftData = 5 (left) + 0 (right) = 5.
   - Update `root->data` to 5.

Final Tree Node Values After `changeTree:
- Root (5)
- Left Child (5)
    - Left Child (5)
- Right Child (0)

Step 2: Call `isSumProperty(root)`
Call `isSumProperty(root)` where `root->data` = 5

1. Left Subtree of Root:
   - Call `isSumProperty(root->left)` where `root->left->data` = 5
   - Call `isSumProperty(root->left->left)` where `root->left->left->data` = 5 (leaf node) → returns true.
   - Call `isSumProperty(root->left->right)` (it is NULL) → returns true.
   - Child Sum = 5 (left) + 0 (right) = 5. 
   - Check if `5 == 5` (true), return true.

2. Right Subtree of Root:
   - Call `isSumProperty(root->right)` where `root->right->data` = 0 (leaf node) → return true.

3. Back to Root:
   - Child Sum = 5 (left) + 0 (right) = 5.
   - Check if `5 == 5` (true), return true.
   
Conclusion
Both functions successfully ran on the tree without any errors. The final results are:
After applying `changeTree`, the transformed tree values are:
      5
     / \
    5   0
   /
  5
The property `isSumProperty` returns `true`, indicating every node has a value equal to the sum of its children's values. 