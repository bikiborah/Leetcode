class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        int cnt=0;
        int i=0;
        while(ans!=0){
          if(ans & 1){
            cnt++;
          }
          i++;
          ans=ans/2;
        }

        return cnt;
    }
};