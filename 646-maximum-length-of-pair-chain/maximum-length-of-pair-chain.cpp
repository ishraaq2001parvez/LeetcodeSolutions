class Solution {
public:
    bool follows(vector<int> a, vector<int> b){
      return a[1]<b[0]; 
    }
    int findLongestChain(vector<vector<int>>& pairs) {
      sort(pairs.begin(), pairs.end());
        vector<int> dp(pairs.size(), 1); 
        // int res=1; 
        for(int i=1;i<pairs.size();i++){
          for(int j=i-1;j>=0;j--){
            if(pairs[j][1]<pairs[i][0]){
              dp[i]=max(dp[i], dp[j]+1); 
            //   res=max(res,dp[i]); 
            }
          }
        }
        return *max_element(dp.begin(), dp.end());
    }
};