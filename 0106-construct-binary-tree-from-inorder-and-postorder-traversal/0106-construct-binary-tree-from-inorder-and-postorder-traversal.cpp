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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder){
        int n = inorder.size();
        if(n==0)return NULL;
        TreeNode* root= new TreeNode(postorder[n-1]);
        int left=0;
        while(inorder[left]!=postorder[n-1]){
            left++;
        }
        vector<int> newpostleft(postorder.begin(),postorder.begin()+left);
        vector<int> newinoleft(inorder.begin(),inorder.begin()+left);
        vector<int> newpostright(postorder.begin()+left,postorder.end()-1);
        vector<int> newinoright(inorder.begin()+left+1 ,inorder.end());

        root->left=build(newinoleft,newpostleft);
        root->right=build(newinoright,newpostright);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder,postorder);
    }
};