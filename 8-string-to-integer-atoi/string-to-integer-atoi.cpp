class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        
        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }
 
        // Step 2: Determine the sign
        int sign = 1;
        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        } else if (i < n && s[i] == '+') {
            i++;
        }
 
        // Step 3: Parse digits and calculate result
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            i++;
 
            // Step 4: Check for overflow
            if (result * sign >= INT_MAX) {
                return INT_MAX;
            }
            if (result * sign <= INT_MIN) {
                return INT_MIN;
            }
        }
 
        // Step 5: Return the result with sign
        return result * sign;
    }
};