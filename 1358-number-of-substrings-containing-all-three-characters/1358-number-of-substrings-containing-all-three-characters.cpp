class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int n=s.size();
        int count = 0;

        unordered_map<char,int>st;
        while(r<n){
            st[s[r]]++;
            while(st.size()==3){
            count=count+(n-r);
            st[s[l]]--;
            if(st[s[l]]==0)
            st.erase(s[l]);
            l++;
            }
        
            r++;
         }
        return count;
    }
};