class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int cnt=0;

        unordered_map<int,int> mpp;

        for(int i=0;i<nums.size();i++){
          sum+=nums[i];
          int x=sum-k;
      
          if(x==0){
            cnt++;
          }


          if(mpp.find(x)!=mpp.end()){
            cnt+=mpp[x];
          }
          mpp[sum]++;
          
        }
        return cnt;
    }
};