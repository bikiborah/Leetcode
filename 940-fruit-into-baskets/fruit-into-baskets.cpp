class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mpp;
        int ml=INT_MIN;
        int l=0;
        int r=0;

        while(r<fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size()<=2){
                ml=max(r-l+1,ml);
                r++;
            }
            else{
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;
                r++;
            }
        }

        return ml;
    }
};