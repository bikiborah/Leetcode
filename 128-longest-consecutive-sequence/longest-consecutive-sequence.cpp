class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for (auto x : nums) {
            st.insert(x);
        }

        int largest = 0;

        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;

                while (st.find(x + 1) != st.end()) {
                    x++;
                    cnt++;
                }

                largest = max(largest, cnt);
            }
        }

        return largest;
    }
};