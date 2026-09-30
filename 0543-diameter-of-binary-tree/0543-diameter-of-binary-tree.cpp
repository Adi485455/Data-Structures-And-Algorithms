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
    int helper_diameter(TreeNode* root,int &ans){
        if (root==NULL) return 0;
        int left_height = helper_diameter(root->left,ans);
        int right_height = helper_diameter(root->right,ans);
        
        int curr_diameter = left_height+right_height +1;
        ans = max(ans,curr_diameter);
        return 1+max(left_height,right_height);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        helper_diameter(root,ans);
        return ans-1;
    }
};