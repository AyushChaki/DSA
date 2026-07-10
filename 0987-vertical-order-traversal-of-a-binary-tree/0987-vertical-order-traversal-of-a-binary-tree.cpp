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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        vector<vector<int>>ans1;
        vector<int>ans2;
        if(root==NULL)
        return ans1;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>>temp=q.front();
            q.pop();
            TreeNode* f=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            nodes[hd][lvl].push_back(f->val);
            if(f->left)
            q.push(make_pair(f->left,make_pair(hd-1,lvl+1)));
            if(f->right)
            q.push(make_pair(f->right,make_pair(hd+1,lvl+1)));
        }
         for (auto i : nodes) {
            vector<int> ans2;

            for (auto j : i.second) {
                sort(j.second.begin(), j.second.end());

                for (auto k : j.second) {
                    ans2.push_back(k);
                }
            }

            ans1.push_back(ans2);
        }

        return ans1;
        
        
    }
};