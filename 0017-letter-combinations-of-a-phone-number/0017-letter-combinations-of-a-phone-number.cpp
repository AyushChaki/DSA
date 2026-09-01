class Solution {
public:
    vector<string> ans;
    void solve(string &digits,string &curr,int index,string map[])
    {
        if(curr.length()>=digits.size()){
            ans.push_back(curr);
            return;
        }
        int number=digits[index]-'0';
        string s=map[number];
        for(int i=0;i<s.length();i++){
            curr.push_back(s[i]);
            solve(digits,curr,index+1,map);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
      string curr;
      string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      solve(digits,curr,0,map);
      return ans;  
    }
};