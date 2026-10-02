class Solution {
public:
    void reverseString(vector<char>& s) {
         // Empty vector
        if(s.empty()) {
            return;
        }

        // Stop when we reach the middle
        static int ind = 0;

        if(ind >= s.size() / 2) {
            ind = 0;
            return;
        }

        swap(s[ind], s[s.size() - ind - 1]);

        ind++;

        reverseString(s);
    }
};