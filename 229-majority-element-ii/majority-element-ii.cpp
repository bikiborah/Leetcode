class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        set<int> st;
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]>n/3){
                st.insert(nums[i]);
            }
        }
        vector<int> ans(st.begin(),st.end());
        
        return ans;
    }
};