class Solution {
private:
    bool solve(string &s, int ind, int val, int &n,
               vector<vector<int>> &dp) {

        if(val < 0) return false;

        if(ind == n){
            return val == 0;
        }

        if(dp[ind][val] != -1)
            return dp[ind][val];

        bool ans = false;

        if(s[ind] == '('){
            ans = solve(s, ind+1, val+1, n, dp);
        }
        else if(s[ind] == ')'){
            ans = solve(s, ind+1, val-1, n, dp);
        }
        else{
            bool a = solve(s, ind+1, val+1, n, dp);
            bool b = solve(s, ind+1, val-1, n, dp);
            bool c = solve(s, ind+1, val, n, dp);

            ans = a || b || c;
        }

        return dp[ind][val] = ans;
    }

public:
    bool checkValidString(string s) {

        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(s, 0, 0, n, dp);
    }
};