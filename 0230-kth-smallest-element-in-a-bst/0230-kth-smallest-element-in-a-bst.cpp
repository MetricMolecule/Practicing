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
    int ans=0;
    int count=0;
    void smallorder(TreeNode* root, int x){
        if(root==NULL) return;

        smallorder(root->left,x);
        count++;
        if(count==x){
            ans=root->val;
            return;
        } 
        smallorder(root->right,x);
    }
    int kthSmallest(TreeNode* root, int k) {
        smallorder(root,k);
        return ans;
    }
};