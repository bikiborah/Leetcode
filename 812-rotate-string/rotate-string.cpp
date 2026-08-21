class Solution {
public:
    bool rotateString(string s, string goal) {
         if(s.size()!=goal.size()){
            return false;
         }
         
         string z=s;
         for(int i=0;i<s.size();i++){
           
            z=z.substr(1)+z[0];
            if(z==goal){
                return true;
            }
         }
         return false;
    }
};