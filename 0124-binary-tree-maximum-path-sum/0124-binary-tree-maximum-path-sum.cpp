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
    int maxsum=INT_MIN;
    int sumup(TreeNode* root){
        if(root==NULL) return 0;
        int left=sumup(root->left);
        int right=sumup(root->right);
        left=max(0,left);                   // make sure to not take negative values upward
        right=max(0,right);                 // its a BOTTOM UP approach
        
        int currsum = left+right+root->val; // make cureentsum sum of node value and left and right
        maxsum=max(maxsum,currsum);         // update the global maxima
        return root->val+max(left,right);   // return single side maxima along with node val
    }
    int maxPathSum(TreeNode* root) {
        int x=sumup(root);
        return maxsum;
    }
};