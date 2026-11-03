class Solution {
public:
    int candy(vector<int>& ratings) {
        //your code goes here
        int sum = 1; int i = 1;
        int n = ratings.size();
        // go straight
        while(i < n){
            if(ratings[i] == ratings[i-1]){
              sum = sum + 1;
              i++;
              continue;
            }

            int peak = 1;
            // inc slope
            while(i < n && ratings[i] > ratings[i-1]){
              peak ++;
              sum += peak;
              i++;
            }
            int down = 1;
            // dec slope
            while(i < n && ratings[i] < ratings[i-1]){
              sum += down;
              down++;
              i++;
            }

            // assign the max of a peak vertex with max one
            if(peak < down){
              sum += (down - peak);
            }     
        }

        return sum;

    }
};