class Solution {
public:

    string substr(int x,int y,string& s){
        string z;
        for(int i=x;i<=y;i++){
            z+=s[i];
        }
        return z;
    }

    string minWindow(string s, string t) {
        int l=0;int r=0;
        string ans;
        int sindex;
        int cnt=0;
        int ml=INT_MAX;
        int n=s.size();
        int m=t.size();
        int hash[256]={0};

        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }

        while(r<s.size()){
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
            if(cnt==m){
                while(cnt==m){
                    if(r-l+1<ml){
                        ml=min(r-l+1,ml);
                        sindex=l;
                    }
                    hash[s[l]]++;
                    if(hash[s[l]]>0){
                        cnt--;
                    }
                    l++;
                }
            }
        r++;
        }

        if(ml==INT_MAX) return "";
        ans=substr(sindex,sindex+ml-1,s);
        return ans;
    }
};