class Solution {
public:

    bool isPalindrome(vector<string> store){
      bool check = true;
      for(int i = 0; i < store.size(); i++){
        int j = 0;
        int k = store[i].size() - 1;

        while(j < k){
          if(store[i][j] != store[i][k]){
            check = false;
          }
          j++;
          k--;
        }
      }

      return check;
    }




    void solve(int ind,vector<string> store,vector<vector<string>> &ans,string &s){
      if(ind == s.length()){
        if(isPalindrome(store)){
          ans.push_back(store);
          return;
        }
        else{
          return;
        }

      }
        for(int i = ind; i < s.length(); i++){
          store.push_back(s.substr(ind,i - ind + 1));
          if(isPalindrome(store) == true){
            
          solve(i + 1,store,ans,s);
          }
          store.pop_back();
        }
    }
    vector<vector<string> > partition(string s) {
        //your code goes here
        vector<vector<string>> ans;
        solve(0,{},ans,s);
        return ans;
    }
};