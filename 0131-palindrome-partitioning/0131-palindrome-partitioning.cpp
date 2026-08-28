class Solution {
public:
    vector<vector<string>> ans;
    bool palindrome(string &s,int left,int right) {
        if(left >= right)
            return true;
        if(s[left] != s[right])
            return false;
        return palindrome(s, left + 1, right - 1);
    }
    void solve(string &s, int left, vector<string>& curr) {
        if (left == s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = left; i < s.size(); i++) {
            if (palindrome(s, left, i)) {
                curr.push_back(s.substr(left, i - left + 1));
                solve(s, i + 1, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(s, 0, curr);
        return ans;
    }
};