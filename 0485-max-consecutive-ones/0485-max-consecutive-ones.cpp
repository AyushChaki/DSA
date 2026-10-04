class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxsum=0;
        int left=0;
        int right=0;
        int n=nums.size();
        int sum=0;
        while(right<(n)){

           if(nums[right]==1){
            sum=sum+nums[right];
            maxsum=max(maxsum,sum);
           }
           else if (nums[right]==0) {
    
            sum=0;
           }
           right++;
            
           

        }
            return maxsum;        
    } 
};