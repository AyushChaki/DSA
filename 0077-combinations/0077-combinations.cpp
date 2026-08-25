class Solution {
public:
    vector<vector<int>> res;
    void solve(int n,int k,vector<int>&curr,int index){
        if(curr.size()==k){
            res.push_back(curr);
            return;
        }
        for(int i=index;i<=n;i++){
            curr.push_back(i);
            solve(n,k,curr,i+1);
            curr.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
       vector<int>curr;
       solve(n,k,curr,1);
       return res; 
    }
};