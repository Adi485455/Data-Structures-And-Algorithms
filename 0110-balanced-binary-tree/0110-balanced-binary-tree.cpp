/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode * root){
        if (root == NULL) return 0;

        // check the left height
        int left_height = helper(root->left);
        if(left_height == -1) return -1;

        int right_height = helper(root->right);
        if (right_height == -1) return -1;

        if(abs(left_height-right_height)>1) return -1; 

        return 1 + max(right_height,left_height);
    }
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
        
    }
};