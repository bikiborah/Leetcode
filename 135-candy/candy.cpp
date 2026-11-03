class Solution {
private:
    int sum(vector<int> arr) {
        int total = 0;

        for(auto it : arr) {
            total += it;
        }

        return total;
    }

public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        vector<int> List(n, 1);

        // Going right
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1]) {
                List[i] = List[i-1] + 1;
            }
        }

        vector<int> Right = List;

        List = vector<int>(n, 1);

        // Going left
        for(int i = n-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) {
                List[i] = List[i+1] + 1;
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans += max(List[i], Right[i]);
        }

        return ans;
    }
};