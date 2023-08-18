class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int>(n, 0)); 
        for(auto& i:roads){
            adj[i[0]][i[1]] = adj[i[1]][i[0]] = 1;
        }
        int res=0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;j++){
                res=max(res, accumulate(begin(adj[i]), end(adj[i]), 0) + accumulate(begin(adj[j]), end(adj[j]), 0) - adj[i][j]); 
            }
        }
        return res;
    }
};