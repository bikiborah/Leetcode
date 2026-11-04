
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int flips = 0;
        int Mxlen = 0;

        while(r < nums.size()) {
            if(nums[r] == 0) {
                if(flips < k) {
                    flips++;
                    r++;
                }
                else {
                    if(nums[l] == 0) {
                        flips--;
                    }
                    l++;
                }
            }
            else {
                r++;
            }

            Mxlen = max(Mxlen, r - l);
        }

        return Mxlen;
    }
};
