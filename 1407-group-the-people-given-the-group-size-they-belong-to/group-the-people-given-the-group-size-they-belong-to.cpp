class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        map<int,vector<int>> m;
        for(int i=0;i<size(g);i++){
            m[g[i]].push_back(i); 
        }
        vector<vector<int>> res; 
        for(auto& [k,v]:m){
            vector<int> p; 
            for(int i=0;i<size(v);i++){
                if(i!=0&&i%k==0){
                    res.push_back(p);
                    p.clear(); 
                }
                p.push_back(v[i]); 
            }
            res.push_back(p); 
        
        }
        return res;
    }
};