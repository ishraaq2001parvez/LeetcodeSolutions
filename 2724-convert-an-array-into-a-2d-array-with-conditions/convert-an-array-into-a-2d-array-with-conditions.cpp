class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> m;
        for(int& i:nums){
            m[i]++; 
        }
        vector<vector<int>> res;
        for(auto itr=m.begin();itr!=m.end();itr++){
            for(int j=1;j<=itr->second;j++){
                if(j>res.size()){
                    res.push_back(vector<int>{}); 
                }
                res[j-1].push_back(itr->first); 
            }
        }
        return res;
    }
};