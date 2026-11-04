class Solution {
public:
    int characterReplacement(string s, int k) {
        //your code goes here
        int l = 0;
        int r = 0;
        int maxf = 0;
        int hash[26] = {0};
        int Mxlen = 0;

        while( r < s.length()){
          hash[s[r] - 'A'] ++;
          maxf = max(maxf,hash[s[r] - 'A']);
          /* while */ if((r - l + 1) - maxf > k){
            hash[s[l] - 'A'] --;
            l++;
            maxf = 0;
            // for(int i = 0; i < 26; i++){
            //   maxf = max(maxf,hash[i]);
            // }
          }
          if((r - l + 1) - maxf <= k){
            Mxlen = max(Mxlen,(r - l + 1));
          }
          r++;
        }

        return Mxlen;
    }
};