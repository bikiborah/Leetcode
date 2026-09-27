class Solution {
public:
    int maxArea(vector<int>& height) {
       int  i=0;
       int j=height.size()-1;
       int ans=INT_MIN;
       while(i<j){
         int x=min(height[i],height[j]);
         int y=j-i;
         if((x*y)>ans){
            ans=x*y;
         }
         if(height[i]<=height[j]){
            i++;
         }
         else{
            j--;
         }
       }

       return ans;

    }
};