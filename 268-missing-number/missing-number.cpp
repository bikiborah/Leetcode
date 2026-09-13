class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int hash[n+1];
        for(int i=0;i<n+1;i++){
            hash[i]=0;
        }
        int x=0;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]=1;
        }
        for(int i=0;i<n;i++){
            if(hash[i]==0){
               return i;
            }
        }

        return n;

    }
};