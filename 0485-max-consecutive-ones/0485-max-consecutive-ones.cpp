class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxlen=0;
        int left=0;
        int right=0;
        int n=nums.size();
        int len=0;
        while(right<(n)){
                                    
           if(nums[right]==1){
            len=right-left+1;
            maxlen=max(maxlen,len);
           }
           else if (nums[right]==0) {
            left=right+1;    
            len=0;
           }
           right++;
            
           

        }
            return maxlen;        
    } 
};