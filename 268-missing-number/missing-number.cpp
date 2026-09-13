class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int s=(n*(n+1))/2;
        int x=0;
        for(int i=0;i<nums.size();i++){
            x+=nums[i];
        }
        return s-x;
    }
};