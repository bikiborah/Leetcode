class Solution {
public:
    bool canJump(vector<int>& nums) {
        int MxPosICanGo = 0;
        int i = 0;
        while(i < nums.size()){

         if(nums[i] == 0 && MxPosICanGo <= i && MxPosICanGo != nums.size()-1){
          return false;
         }

         MxPosICanGo = max(i+nums[i],MxPosICanGo);
         i++;

        }

        return true;
    }
};