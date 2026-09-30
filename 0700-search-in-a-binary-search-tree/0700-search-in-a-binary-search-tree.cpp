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

    TreeNode* helper_search(TreeNode* root,int val){
        if (root==NULL) return 0;

        if(root->val == val) return root;
        TreeNode* left_search = helper_search(root->left,val);
        if(left_search != NULL) return left_search;

        return helper_search(root->right,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return helper_search(root,val);        
    }
};