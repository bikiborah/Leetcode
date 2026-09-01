class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> posarr;
        vector<int> negarr;
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(nums[i]>0){
               posarr.push_back(nums[i]);
            }
            else{
                negarr.push_back(nums[i]);
            }
        }

        for(int i=0;i<n/2;i++){
            ans.push_back(posarr[i]);
            ans.push_back(negarr[i]);
        }

        return ans;

    }
};