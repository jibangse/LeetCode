class Solution {
public:
    
    int CountChar(char c, string s) {
        //s is a sorted string.
        int cnt = 0;
        for(auto ch : s) {
            if(ch==c) {
                cnt++;
            } else {
                if(cnt>0) break;
            }
        }
        return cnt;
    }
    
    string customSortString(string order, string s) {
        unordered_map<char,int> um;
        string order2=order;
        sort(order2.begin(),order2.end());
        sort(s.begin(),s.end());
                
        for(auto ch : order2) {
            int t = CountChar(ch, s);
            um[ch]=t;
        }
        
        unordered_map<char,int> um2=um;
        string ans = "";
        
        for(char c : order) {
            if(um[c]) {
                while(um[c]>0) {
                    ans+=c; um[c]--;
                }
            }
        }
        
        for(char c : s) {
            if(!um2[c]) ans+=c;
        }
        
        return ans;
    }
};