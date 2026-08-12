class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    list<int> ls;
    vector<vector<int>> ans;
    for(int i=0;i<=(1<<nums.size())-1;i++){
      for(int j=0;j<nums.size();j++){
        if((i & (1<<j))!=0){
            ls.push_back(nums[j]);
        }
      }
    ans.push_back(vector<int> (ls.begin(),ls.end()));
    ls.clear();
    }
    return ans;
    }
};