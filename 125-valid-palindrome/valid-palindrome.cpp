class Solution {
public:

    bool isPalindrome(string s) {

        int i = 0;
        int h = s.size() - 1;

        while(i <= h) {

            if(!isalnum(s[i])) {
                i++;
                continue;
            }

            if(!isalnum(s[h])) {
                h--;
                continue;
            }

            if(tolower(s[i]) != tolower(s[h])) {
                return false;
            }

            i++;
            h--;
        }

        return true;
    }
};