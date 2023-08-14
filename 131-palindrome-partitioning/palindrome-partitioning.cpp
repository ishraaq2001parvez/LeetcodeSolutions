class Solution {
public:
    vector<vector<string>> res; 
    void dfs(string& s, int i, vector<string> v){
        if(i==s.length()){
            res.push_back(v);
        }
        for(int j=i+1;j<=s.length();j++){
            string p = string(begin(s)+i, begin(s)+j); 
            if(p==string(p.rbegin(), p.rend())){
                v.push_back(p); 
                dfs(s, j, v); 
                v.pop_back(); 
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s, 0, vector<string>{}); return res;
    }
};