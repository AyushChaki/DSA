class Solution {
public:
    void subsets(int index,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans){
        ans.push_back(curr);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1])
            continue;
            curr.push_back(nums[i]);
            subsets(i+1,nums,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<int> curr;
       sort(nums.begin(),nums.end());
       vector<vector<int>>ans;
       subsets(0,nums,curr,ans);
       return ans; 
    }
};