class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=size(nums)-1; 
        while(l<=r){
            int mid = l+(r-l)/2; 
            if(nums[mid]>nums.back()){
                l=mid+1; 
            }
            else{
                r=mid-1;
            }
        }
        return nums[l];
    }
};