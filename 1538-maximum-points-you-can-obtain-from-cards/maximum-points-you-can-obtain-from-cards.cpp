class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0; int rsum=0;
        int ml=0;
        int x=cardPoints.size()-1;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        ml=lsum;
        for(int j=k-1;j>=0;j--){
            lsum=lsum-cardPoints[j];
            rsum+=cardPoints[x];
            ml=max(ml,lsum+rsum);
            x--;
        }

        return ml;
    }

};