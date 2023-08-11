class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(begin(coins), end(coins)); 

        vector<int> dp(amount+1, 0); dp[0]=1;
        for(int i=0;i<size(coins);i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]+=dp[j-coins[i]]; 
            }
        }
        return dp.back();
    }
};