class Solution {
public:
   
    int need(vector<int> &nums,int k){
        if(k<0) return 0;
        int l=0;int r=0;int sum=0;int cnt=0;
        while(r<nums.size()){
            sum=sum+nums[r]%2;
            while(sum>k){
                sum=sum-nums[l]%2;
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=need(nums,k)-need(nums,k-1);
        return ans;
    }
};