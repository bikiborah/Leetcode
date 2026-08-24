class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     int l=0,r=0;
     int ml=INT_MIN;
     int zeroes=0;
     while(r<nums.size()){
     
     if(nums[r]==1){
        int len=r-l+1;
        ml=max(ml,len);
        r++;
     }   
     else if(nums[r]==0){
        if(zeroes<k){
            zeroes++;
            ml=max(r-l+1,ml);
            r++;
        }
        else if(zeroes>=k){
            while(nums[l]>0){
                l++;
            }
               zeroes--;
               l++;
        }
     }

    }
     return ml;
    }
};