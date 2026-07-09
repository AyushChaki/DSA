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
        vector<vector<int>> result;
        if(root==NULL)
        return result;
        queue<TreeNode*> q;
        q.push(root);
        bool l2r=true;
        while(!q.empty()){
            int size=q.size();
            vector<int> ans(size);
            for(int i=0;i<size;i++){
                TreeNode* f=q.front();
                q.pop();
                int index=l2r?i:size-i-1;
                ans[index]=f->val;
                if(f->left)
                q.push(f->left);
                if(f->right)
                q.push(f->right);
            }
            l2r=!l2r;
            result.push_back(ans);
        }
        return result;
        
    }
};