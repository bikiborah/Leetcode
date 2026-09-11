class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int cnt=0;
        while(i<nums.size()){
            if(i+1<nums.size() && nums[i]==nums[i+1]){
                i++;
            }
            else{
                nums[cnt]=nums[i];
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};