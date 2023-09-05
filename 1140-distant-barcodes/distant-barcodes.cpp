class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        map<int,int> m1;
        for(int& i:b) m1[i]++;
        priority_queue<pair<int,int>> pq; 
        for(auto& [k,v]:m1) pq.push({v, k}); 
        vector<int> v;
        while(!pq.empty()){
            auto [k1, v1] = pq.top();pq.pop(); 
            if(k1==1 && pq.empty()){
                v.push_back(v1); return v;
            }
            auto [k2, v2] = pq.top(); pq.pop(); 
            k1--; k2--;
            v.push_back(v1); v.push_back(v2); 
            if(k1>0) pq.push({k1, v1});
            if(k2>0) pq.push({k2, v2}); 
        }
        return v;
    }
};