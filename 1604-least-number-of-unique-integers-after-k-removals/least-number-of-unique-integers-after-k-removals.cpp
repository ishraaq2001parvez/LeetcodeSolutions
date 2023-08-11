class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m;
        for(int& i:arr){m[i]++; }
        priority_queue<pair<int,int>> pq; 
        for(auto& [key,v]:m){
            pq.push({-v,key}); 
        }
        while(k--){
            auto [v, n] = pq.top(); pq.pop(); 
            if(v!=-1){
                pq.push({v+1, n}); 
            }
            else{
                m.erase(m.find(n)); 
            }
        }
        return size(m);

    }
};