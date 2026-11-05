class Solution {
public:
    int LessthanKSub(vector<int>& nums, int k) {
        if (k <= 0) return 0;

        int l = 0;
        int r = 0;
        unordered_map<int, int> mpp;
        int NoOfSubs = 0;

        while (r < nums.size()) {
            mpp[nums[r]]++;

            while (mpp.size() > k) {
                mpp[nums[l]]--;

                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }

                l++;
            }

            NoOfSubs += (r - l + 1);
            r++;
        }

        return NoOfSubs;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return LessthanKSub(nums, k) - LessthanKSub(nums, k - 1);
    }
};