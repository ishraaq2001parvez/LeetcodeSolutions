class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> m;
        for(char& c:s){
            m[c]++; 
        }
        priority_queue<pair<int,int>> pq; 
        for(auto& [key, value]: m){
            pq.push({value, key}); 
        }
        string res=""; 
        while(!pq.empty()){
            // cout<<res<<endl;
            auto [k1, v1] = pq.top(); pq.pop(); 
            // printf("%d %c ", k1, v1);
            if(pq.empty()){
                return k1==1?(res+string(1,v1)):""; 
            }
            
            auto [k2, v2]=  pq.top(); pq.pop(); 
            res+=string(1, v1)+string(1,v2); 
            if(k1-1>0)pq.push({--k1, v1});
            if(k2-1>0)pq.push({--k2, v2});
        }
        return res;

    }
};