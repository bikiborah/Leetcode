class Solution {
private:
static bool comp(vector<int> &a,vector<int> &b){
      if(a[0] < b[0]){
        return true;
      }
      else if(a[0] == b[0]){
        return a[1] > b[1];
      }
      return false;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& Intervals, vector<int>& newInterval){
        //your code goes here
        Intervals.push_back(newInterval);

        sort(Intervals.begin(),Intervals.end(),comp);

        vector<vector<int>> ans;

        ans.push_back(Intervals[0]);

        for(int i = 1; i < Intervals.size(); i++){
          if(Intervals[i][0] <= ans.back()[1]){
              ans.back()[1] = max(ans.back()[1],Intervals[i][1]);
          }
          else{
            ans.push_back(Intervals[i]);
          }
        }

        return ans;

    }
};