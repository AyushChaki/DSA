class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>hash;
        int req=0;
        hash[0]=1;
        int sum=0;
        int count=0;
        for(int r:nums){
            sum=sum+r;
            req=sum-goal;
            if(hash.find(req)!=hash.end()){
            count=count+hash[req];
            }
            hash[sum]++;
        }
        return count;
    }
};