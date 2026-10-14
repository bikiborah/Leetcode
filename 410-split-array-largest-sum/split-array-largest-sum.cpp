class Solution {
public:
    int max(vector<int>& nums) {
        int mx = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx) {
                mx = nums[i];
            }
        }

        return mx;
    }

    int sum(vector<int>& nums) {
        int total = 0;

        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }

        return total;
    }

    bool ispossible(vector<int>& nums, int k, int mid) {
        int subarrays = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] <= mid) {
                sum += nums[i];
            } else {
                subarrays++;
                sum = nums[i];
            }
        }

        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = max(nums);
        int high = sum(nums);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (ispossible(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};