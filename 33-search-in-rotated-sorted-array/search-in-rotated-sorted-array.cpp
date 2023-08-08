class Solution {
public:
    int search(vector<int>& nums, int& target) {
        int l=0, r=size(nums)-1, mid;
        while(l<=r){
            mid = (l+r)/2;
        
            if(nums[mid]>nums.back()){
                l=mid+1; 
            }
            else r=mid-1; 
        }
        // printf("%d", l);
        return binary_search(begin(nums), begin(nums)+l, target)?distance(begin(nums), lower_bound(begin(nums), begin(nums)+l, target)):binary_search(begin(nums)+l, end(nums), target)?distance(begin(nums), lower_bound(begin(nums)+l, end(nums), target)):-1;
        
    }
};