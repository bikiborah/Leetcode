class Solution {
public:
    string frequencySort(string s) {
         int hash[256] = {0};


        for(int i = 0; i < s.length(); i++) {
            hash[s[i]]++;
        }

        string ans;

        for(int freq = s.length(); freq >= 1; freq--) {

            for(int i = 0; i < 256; i++) {

                if(hash[i] == freq) {
                    
                    for(int j=0;j<freq;j++){
                        ans+=(char(i));
                    }
                    
                }
            }
        }

        return ans;
    }
};