/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root,TreeNode* p, TreeNode* q){

        // Imp point here is the node can be ancestor of itself

        if (root==p || root==q || root== NULL) return root;

        // check on the left side & rigtht side if the anscestor exists
        TreeNode* left_check = helper(root->left,p,q);
        TreeNode* right_check = helper(root->right,p,q);

        // Now if say we've find the node one of the p & q (as node can be ancestor of itself)
        // Checking both side we find the p and q

        if(left_check != NULL && right_check != NULL) return root;

        // if only find from the left side both p and q

        if(left_check!=NULL) return left_check;
        // only from the right side we find p & q
        return right_check;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
        
    }
};