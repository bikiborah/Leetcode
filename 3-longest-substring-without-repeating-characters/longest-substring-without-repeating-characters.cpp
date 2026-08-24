class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       if(s.size()==0){
        return 0;
       }
       
       int l=0;
       int r=0;
       int maxlen=INT_MIN;
       int hash[256]={0};
       
       while(r<s.size()){
        while(hash[s[r]]>=1){
            hash[s[l]]--;
            l++;
        }
        hash[s[r]]++;
        maxlen=max(r-l+1,maxlen);
        r++;
       }
       return maxlen;
    }
};