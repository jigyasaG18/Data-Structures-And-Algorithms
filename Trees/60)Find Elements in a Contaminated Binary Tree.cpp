Find Elements in a Contaminated Binary Tree
Given a binary tree with the following rules:
root.val == 0
For any treeNode:
If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.
Implement the FindElements class:
FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
bool find(int target) Returns true if the target value exists in the recovered binary tree.
 
Example 1:
Input
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True 

Example 2:
Input
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False

Example 3:
Input
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
Output
[null,true,false,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True

class FindElements {
    public:
    unordered_map<int,bool>mpp;
    void recover(TreeNode* root){
        if(root->left){
            root->left->val=root->val*2+1;
            mpp[root->left->val]=true;
            recover(root->left);
        }
        if(root->right){
            root->right->val=root->val*2+2;
            mpp[root->right->val]=true;
            recover(root->right); 
        }
    }
        FindElements(TreeNode* root) {
            root->val=0;
            mpp[0]=true;
            recover(root);
        }
        
        bool find(int target) {
            return mpp[target];
        }
    };