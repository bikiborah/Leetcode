class Solution {
private:
    int solve(int ind, int &n, vector<int> &nums, vector<int> &dp) {

        if(ind >= n-1) {
            return 0;
        }

        if(nums[ind] == 0) {
            return INT_MAX;
        }

        if(dp[ind] != -1) return dp[ind];

        int ans = INT_MAX;

        for(int i = 1; i <= nums[ind]; i++) {

            if(ind + i < n) {

                int temp = solve(ind+i, n, nums, dp);

                if(temp != INT_MAX) {
                    ans = min(ans, temp + 1);
                }
            }
        }

        return dp[ind] = ans;
    }

public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(0, n, nums, dp);
    }
};