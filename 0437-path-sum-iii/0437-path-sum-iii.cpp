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
    void solve(TreeNode* root,vector <int>&path,int &count,int targetsum)
    {
        if(root==NULL)
        return;
        path.push_back(root->val);
        solve(root->left,path,count,targetsum);
        solve(root->right,path,count,targetsum);
        long long size=path.size();
        long long sum=0;
        for(int i=size-1;i>=0;i--){
            sum+=path[i];
            if(sum==targetsum)
            count++;
        }
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetsum) {
        vector <int> path;
        int count=0;
        solve(root,path,count,targetsum);
        return count;
    }
};