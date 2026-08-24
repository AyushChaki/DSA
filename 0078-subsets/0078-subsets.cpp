class Solution {
public:
    vector<vector<int>>res;
    void s(vector<int>& nums,int index,vector<int>&a){
        if(index==nums.size()){
        res.push_back(a);
        return;
        }
        a.push_back(nums[index]);
        s(nums,index+1,a);
        a.pop_back();
        s(nums,index+1,a);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        s(nums,0,a);
        return res;
    }
};