class Solution {
private:
  void solve(int ind,vector<vector<int>> &ans,int &n,vector<int> &store,vector<int> &nums){
        if(ind >= n){
          ans.push_back(store);
          return ;
        }
        store.push_back(nums[ind]);
        solve(ind + 1,ans,n,store,nums);
        store.pop_back();
        solve(ind + 1,ans,n,store,nums);
  }
public:	
    vector<vector<int> > subsets(vector<int>& nums) {
        //your code goes here
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> store;
        solve(0,ans,n,store,nums);
        return ans;
    }
};