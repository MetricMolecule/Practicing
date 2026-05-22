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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                TreeNode* top=q.front();
                q.pop();
                temp.push_back(top->val);
                if(top->left!=NULL) q.push(top->left);
                if(top->right!=NULL) q.push(top->right);
            }
            ans.push_back(temp);
        }
        int n=ans.size();
        for(int i=0;i<n;i++){
            if(i%2!=0){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};