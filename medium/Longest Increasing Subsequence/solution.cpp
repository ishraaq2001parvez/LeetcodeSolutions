class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1, INT_MAX); 
        dp[0]=-INT_MAX; 
        for(int i=0;i<nums.size();i++){
            int j=upper_bound(dp.begin(), dp.end(), nums[i])-dp.begin(); 
            if(dp[j-1]<nums[i]&&nums[i]<dp[j]){
                dp[j]=nums[i]; 
            }
        }
        int ans=-1;
        for(int i=1;i<=nums.size();i++){
            if(dp[i]<INT_MAX){
                ans=i;
            }
        }
        return ans;
            
    }
};