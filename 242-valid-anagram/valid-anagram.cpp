class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
        return false;
      }

      unordered_map<char,int> mp1;
      unordered_map<char,int> mp2;
      

      for(int i=0;i<s.length();i++){
        mp1[s[i]]++;
      }
      for(int i=0;i<t.length();i++){
        mp2[t[i]]++;
      }

      for(auto [key,value]:mp1){
        if(mp2.find(key)!=mp2.end() && value==mp2[key]){
          continue;
        }
        else{
          return false;
        }
      }
      return true;
        
    }
};