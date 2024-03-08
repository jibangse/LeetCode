class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int num:nums) {
            um[num]++;
        }
        int maxFreq=0;
        for(auto entry:um) {
            maxFreq=max(maxFreq,entry.second);
        }
        
        int maxElem=0;
        
        for(auto entry:um) {
            if(entry.second==maxFreq) {
                maxElem++;
            }
        }
        
        int ans = maxFreq*maxElem;
        return ans;
    }   
};