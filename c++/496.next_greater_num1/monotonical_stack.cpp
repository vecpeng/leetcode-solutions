class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> monotonicalStack;
        vector<int> result2;
        unordered_map<int, int> numsMap;
        for(int i = 0; i < nums2.size(); i++) {
            while( !monotonicalStack.empty() && nums2[i] > monotonicalStack[monotonicalStack.size() - 1]) {
                numsMap[monotonicalStack[monotonicalStack.size() - 1]] = nums2[i];
                cout<<nums2[i]<<endl;
                monotonicalStack.pop_back();
            }
            monotonicalStack.push_back(nums2[i]);
        }
        for(auto num:nums1) {
            numsMap[num]?result2.push_back(numsMap[num]):result2.push_back(-1);
        }
        return result2;
    }
};
