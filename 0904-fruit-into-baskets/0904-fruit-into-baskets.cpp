class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int left=0;
        int count = 0;
        int ans = 0;
        vector<int> seen(100000, 0);
        for(int right=0;right<fruits.size();right++){
            if(seen[fruits[right]]==0){
                count++;
            }
            seen[fruits[right]]++;
            while(count>2){
                seen[fruits[left]]--;
                if(seen[fruits[left]]==0){
                    count--;
                }
                left++;
            }
            ans = max(right-left+1,ans);

        }
        return ans;
    }
};