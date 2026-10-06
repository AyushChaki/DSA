class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int len=0;
        int maxlen=0;
        int n=nums.size();
        for(int x:st){
            if(st.find(x-1)==st.end()){
                int current=x;
                int len=1;
                while(st.find(current+1)!=st.end()){
                    len++;
                    current++;
                }
                maxlen=max(maxlen,len);
            }

        }
        return maxlen;        
    }
};