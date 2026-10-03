class Solution {
public:
    string largestOddNumber(string num) {
        int start = 0;

        // Remove leading zeros
        while (start < num.length() && num[start] == '0') {
            start++;
        }

        // Find last odd digit
        int end = num.length() - 1;

        while (end >= start && (num[end] - '0') % 2 == 0) {
            end--;
        }

        if (start > end)
            return "";

        return num.substr(start, end - start + 1);
    }
};