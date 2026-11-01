class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int S = 0;
        int C = 0;

        while(S < g.size() && C < s.size()){
         if(g[S] <= s[C]){
          S++;
         }
         C++;
        }
        
        return S;
    }
};