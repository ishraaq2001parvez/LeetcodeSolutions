class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool> dp(size(nums)+1, false); dp[0]=true; 
        nums.insert(begin(nums), 0); 
        for(int i=2;i<size(dp);i++){
            if(nums[i]==nums[i-1]){
                dp[i]=dp[i]||dp[i-2]; 
            }
            if(i>=3){
                if((nums[i]==nums[i-1] && nums[i-1]==nums[i-2]) || (nums[i]==nums[i-1]+1 && nums[i-1]==nums[i-2]+1)){
                    dp[i]= dp[i-3]||dp[i];
                }
            }

        }
        return dp.back();
    }
};