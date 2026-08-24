class Solution {
public:
    vector<vector<int>> res;
    void s(vector<int>& candidates,int target,int index,vector<int>&curr){
        if(index==candidates.size())
        return;
        if(target==0)
        {
            res.push_back(curr);
            return;
        }
        if(candidates[index]>target){
        s(candidates,target,index+1,curr);
        return;
        }
        curr.push_back(candidates[index]);
        s(candidates,target-candidates[index],index,curr);
        curr.pop_back();
        s(candidates,target,index+1,curr);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>c;
        s(candidates,target,0,c);
        return res;
    }
};