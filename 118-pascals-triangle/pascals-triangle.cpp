class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v;
        v.assign(n,vector<int>());
        v[0].push_back(1);
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0){
                    v[i].push_back(v[i-1][j]);
                }
                else if(j==i){
                    v[i].push_back(v[i-1][j-1]);
                }
                else{
                    v[i].push_back(v[i-1][j-1]+v[i-1][j]);
                }
            }
        }
        return v;
    }
};