class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=size(nums)-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>nums.back()){
                l=mid+1; 
            }
            else r=mid-1; 
        }
        printf("%d", l);
        if(binary_search(begin(nums), begin(nums)+l, target)){
            return distance(begin(nums), lower_bound(begin(nums), begin(nums)+l, target)); 
        }
        if(binary_search(begin(nums)+l, end(nums), target)){
            return distance(begin(nums), lower_bound(begin(nums)+l, end(nums), target)); 
        }
        return -1;
    }
};