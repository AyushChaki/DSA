class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        int req=0;
        hash[0]=1;
        int sum=0;
        int count=0;
        for(int r:nums){
            sum=sum+r;
            req=sum-k;
            if(hash.find(req)!=hash.end()){
            count=count+hash[req];
            }
            hash[sum]++;
        }
        return count;
        
    }
};