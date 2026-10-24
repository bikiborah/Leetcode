class Solution {
public:

    void solve(int ind, vector<string> &ans,string s,string &digits,vector<string> &store){
        // BASE CASE
        if(ind == digits.size()){
          ans.push_back(s);
          return;
        }

          int x = digits[ind] - '0';
          for(int i = 0; i < store[x].size(); i ++){
            solve(ind + 1,ans,s + store[x][i],digits,store);
        }
    }





    vector<string> letterCombinations(string digits) {
        //your code goes here
        vector<string> ans;
        vector<string> store = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,ans,"",digits,store);
        
        return ans;
    }
};