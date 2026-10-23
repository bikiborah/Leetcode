class Solution {
public:
    void solve(int ind,string s,vector<string> &ans,int &n){
      if(ind == n){
        ans.push_back(s);
        return;
      }

      if(s.empty(
        
      ) || s.back() == '1'){
        solve(ind+1,s + '0',ans,n);
        solve(ind+1,s + '1',ans,n);
      }
      else{
        solve(ind+1,s + '1',ans,n);
      }
    }


    vector<string> validStrings(int n) {
        vector<string> ans;
        solve(0,"",ans,n);
        return ans;
    }
};