class Solution {
public:
    vector<vector<int>> res; 
    int ans  = INT_MAX;
    void backtrack(vector<int>& cookies, int p){
        if(p==size(cookies)){
            int x = -1; 
            for(auto& i:res) x = max(x, accumulate(begin(i), end(i), 0) );
            ans = min(ans, x); 
            return ;
        }
        for(auto& i:res){
            i.push_back(cookies[p]); 
            backtrack(cookies, p+1); 
            i.pop_back(); 
        }
        return ;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.begin(), cookies.end()); 
        res.resize(k, vector<int>()); 
        backtrack(cookies, 0); 
        return ans;
    }
};