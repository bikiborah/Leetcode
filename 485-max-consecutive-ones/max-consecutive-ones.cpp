class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxlen = nums.size();\
        int cnt=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
         if(nums[i]==1){
            cnt++;
         }

         if(nums[i]==0 || i==nums.size()-1){
            maxi=max(cnt,maxi);
            cnt=0;
         }
        }

        return maxi;
    }
};