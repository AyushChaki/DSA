class Solution {
public:
    vector<string> ans;

    void solve(int open, int close, string curr, int n) {
        if (curr.size()==2*n ) {
            ans.push_back(curr);
            return;
        }
        if (open < n) {
            curr.push_back('(');
            solve(open+1,close,curr,n);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            solve(open,close + 1,curr,n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int op=0;
        int clo=0;
        solve(op, clo, "", n);
        return ans;
    }
};