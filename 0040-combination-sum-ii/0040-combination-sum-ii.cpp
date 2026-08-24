class Solution {
public:
    vector<vector<int>>res;
    void s(vector<int>& candidates, int target,vector<int>&curr,int index){
       if(target==0){
        res.push_back(curr);
        return;
       }
       for(int i=index;i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1]){
            continue;
        }
        if(candidates[i]>target)
        break;
        curr.push_back(candidates[i]);
        s(candidates,target-candidates[i],curr,i+1);
        curr.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>c;
        sort(candidates.begin(),candidates.end());
        s(candidates,target,c,0);
        return res;
    }
};