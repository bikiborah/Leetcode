
class Solution {
private:
    int ExpandOddNCheck(string &s, int i, int j) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
        }
        return (j - i - 1);
    }

public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            int ifoddThenLen = ExpandOddNCheck(s, i, i);
            int ifEvenThenLen = ExpandOddNCheck(s, i, i + 1);

            int len = max(ifEvenThenLen, ifoddThenLen);

            if (len > (end - start + 1)) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};
