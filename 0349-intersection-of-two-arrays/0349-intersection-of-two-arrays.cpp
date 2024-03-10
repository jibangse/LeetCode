class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans = {};
        unordered_set<int> n1(nums1.begin(), nums1.end());
        unordered_set<int> n2(nums2.begin(), nums2.end());
        
        for(auto e : n1) {
            if(n2.find(e)!=n2.end()) {
                ans.push_back(e);
            }
        }
        
        return ans;
    }
};