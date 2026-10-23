class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<int>& store,
               vector<vector<int>>& ans, int& k, int n) {

        if (n == 0 && store.size() == k) {
            ans.push_back(store);
            return;
        }

        if (n < 0 || store.size() >= k || ind == nums.size()) {
            return;
        }

        // Pick
        store.push_back(nums[ind]);
        solve(ind + 1, nums, store, ans, k, n - nums[ind]);
        store.pop_back();

        // Not picked
        solve(ind + 1, nums, store, ans, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> store;
        vector<vector<int>> ans;

        solve(0, nums, store, ans, k, n);
        return ans;
    }
};