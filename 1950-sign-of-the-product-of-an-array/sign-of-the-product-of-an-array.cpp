class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans=1;
        for(int i=0;i<nums.size();i++){
          ans=ans*nums[i];
          if(ans>0){
            ans=1;
          }
          else if(ans<0){
            ans=-1;
          }
          else{
            ans=0;
          }

        }
        if(ans>0){
            return 1;
        }
        else if(ans<0){
            return -1;
        }
        else{
            return 0;
        }
    }
};