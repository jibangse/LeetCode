class Solution {
public:
    int minimumLength(string s) {
        size_t t = s.length();
        int i = 0;
        int j = t-1;
        int ch = 0;
        while(i<j&&s[i]==s[j]) {
            ch=s[i];
            while(i<j&&s[i]==ch) ++i;
            while(i<j&&s[j]==ch) --j;
        }
        
        return s[i]==ch?0:j-i+1;
    }
};