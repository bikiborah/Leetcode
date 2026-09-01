class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mpp;
        int x=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]==1){
                x=nums[i];
            }
        }
        return x;
    }
};