class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(size(stones)==1) return true; 
        if(stones[1]!=1) return false;
        vector<vector<bool>> dp(size(stones), vector<bool>(size(stones)+2, 0));
        dp[0][0]=true;
        dp[1][1] = true; 
        map<int,int> m;;
        for(int i=0;i<size(stones);i++){
            m[stones[i]] = i;
        }
        for(int i=1;i+1<size(dp);i++){
            for(int j=1;j<size(dp[i]);j++){
                
                if(dp[i][j]!=false){
                    if(j!=1 && binary_search(begin(stones), end(stones), stones[i]+j-1)){
                        dp[m[stones[i]+j-1]][j-1] = true;
                    }
                    if(binary_search(begin(stones), end(stones), stones[i]+j)){
                        dp[m[stones[i]+j]][j] = true;
                    }
                    if(binary_search(begin(stones), end(stones), stones[i]+j+1)){
                        dp[m[stones[i]+j+1]][j+1] = true;
                    }
                }
            }
        }
        return any_of(dp.back().begin(), dp.back().end(), [](bool c){
            return c==true; 
        }); 
    }
};