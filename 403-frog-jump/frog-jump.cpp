class Solution {
public:
    bool canCross(vector<int>& stones) {
        

        if(size(stones)==1) return true; //we are at the end
        if(stones[1]!=1) return false; // the frog cannot proceed, as jump of size 1 is insufficient


        // the key idea is to check whether the frog can jump to the next state, with the required jumps
        // we will use a 2d dp array
        //length of dp array = number of stones
        //no. of columns = max number of jumps possible = size of the array stones (assuming each jump is 1 longer than previous)
        // dp[i][j] = whether stone at position i can be reached with length of jump j
        vector<vector<bool>> dp(size(stones), vector<bool>(size(stones), 0));
        dp[0][0]=true; // 0 can be reached with 0 steps
        dp[1][1] = true;  // 1 can be reached with 1 step from stone at 0
        map<int,int> m;; // keeping map for checking where stones[i] is actually located
        for(int i=0;i<size(stones);i++){
            m[stones[i]] = i;
        }


        // bottom-up dp
        for(int i=1;i+1<size(dp);i++){
            for(int j=1;j<size(dp[i]);j++){
                
                if(dp[i][j]){ // if state is satisfied
                    // if there is a stone at stones[i]+ j-1
                    if(j!=1 && binary_search(begin(stones), end(stones), stones[i]+j-1)){

                        dp[m[stones[i]+j-1]][j-1] = true;
                    }

                    // if there is a stone at stones[i]+ j
                    if(binary_search(begin(stones), end(stones), stones[i]+j)){
                        dp[m[stones[i]+j]][j] = true;
                    }

                    // if there is a stone at stones[i]+ j
                    if(binary_search(begin(stones), end(stones), stones[i]+j+1)){
                        dp[m[stones[i]+j+1]][j+1] = true;
                    }
                }
            }
        }

        // return if the last stone can be reached with any number of jumps
        return any_of(dp.back().begin(), dp.back().end(), [](bool c){
            return c==true; 
        }); 
    }
};