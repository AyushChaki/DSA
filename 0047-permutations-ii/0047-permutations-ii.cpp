class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums,vector<int>&curr,vector<int>&vis,int index){
        if(curr.size()==nums.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(vis[i]==1)
            continue;
            if(i>0 && nums[i]==nums[i-1] && vis[i-1]==0)//even if there is a duplicate we are skipping the second one and prefer the first one
            continue;
            curr.push_back(nums[i]);
            vis[i]=1;
            solve(nums,curr,vis,0);
            curr.pop_back();
            vis[i]=0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<int>curr;
        sort(nums.begin(),nums.end());
        vector<int>vis(nums.size(),0);
        solve(nums,curr,vis,0);
        return ans;        
    }
};