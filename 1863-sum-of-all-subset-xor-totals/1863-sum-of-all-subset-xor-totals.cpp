class Solution {
public:
    int dfs(vector<int>&nums,int index,int XOR){
        if(index==nums.size())
        return XOR;
        int a=dfs(nums,index+1,XOR^nums[index]);
        int b=dfs(nums,index+1,XOR);
        return a+b;
    }
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums,0,0);

    }
};