class Solution {
public:
    void solve(int ind,vector<int> &store,vector<vector<int>> &ans,int target,vector<int> &candidates){
        if(target == 0){
          ans.push_back(store);
          return;
        } 

        for(int i = ind; i < candidates.size();i++){
          if(i > ind && candidates[i] == candidates[i-1]){
            continue; 

          }
          if(candidates[i] > target){
            break;
          }
          store.push_back(candidates[i]);
          solve(i+1,store,ans,target-candidates[i],candidates);
          store.pop_back();
        }
   }



    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        //your code goes here
        sort(candidates.begin(),candidates.end());
        vector<int> store;
        vector<vector<int>> ans;
        solve(0,store,ans,target,candidates);
        return ans;
    }
};