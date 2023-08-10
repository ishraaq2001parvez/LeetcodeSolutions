class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return find(begin(nums), end(nums), target)!=end(nums);
    }
};