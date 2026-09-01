class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        int mx=INT_MIN;
        int ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            mx=max(mx,mpp[nums[i]]);
            if(mpp[nums[i]]==mx){
                ans=nums[i];
            }
        }
        return ans;
    }
};