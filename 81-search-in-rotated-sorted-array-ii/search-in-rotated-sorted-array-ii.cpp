class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int& I:nums){
            if(I==target){
                return true; 
            }
        }
        return 0;
    }
};