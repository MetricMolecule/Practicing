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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder){
        int n=preorder.size();
        if(n==0) return NULL;
        TreeNode* root= new TreeNode(preorder[0]);
        int left_part=0;
        while(inorder[left_part]!=preorder[0]){
            left_part++;
        }
        int bar=left_part;
       
        vector<int> newpreleft(preorder.begin()+1 ,preorder.begin()+1+bar);
        vector<int> newinoleft(inorder.begin(),inorder.begin()+left_part);
        vector<int> newpreright(preorder.begin()+bar+1 ,preorder.end());
        vector<int> newinoright(inorder.begin()+left_part+1 ,inorder.end());
         
        root->left=build(newpreleft,newinoleft);
        root->right=build(newpreright,newinoright);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return build(preorder,inorder);
    }
};