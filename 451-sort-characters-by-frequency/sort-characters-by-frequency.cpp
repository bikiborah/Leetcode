class Solution {
public:
    string frequencySort(string s) {

        int freq[128] = {0};

        for(char c : s) {
            freq[c]++;
        }

        vector<pair<int, char>> v;

        for(int i = 0; i < 128; i++) {
            if(freq[i] > 0) {
                v.push_back({freq[i], char(i)});
            }
        }

        sort(v.begin(), v.end(), greater<pair<int, char>>());

        string ans;

        for(auto [count, c] : v) {
            ans.append(count, c);
        }

        return ans;
    }
};