class Pair{
    // our own pair class, for implementing priority queue
    public:
    int first; 
    string second; 
    Pair(int i, string s){
        first=i;
        second=s;
    }
    
};
class Solution {
public:
    bool comp(const Pair& p1, const Pair& p2){
        // custom comparator
        if(p1.first<p2.first){
            return 1;
        }
        if(p1.first>p2.first){
            return 0; 
        }
        return p1.second>p2.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for(auto s:words){
            m[s]++; 
        }
        auto comp=[](const Pair& p1, const Pair& p2)->bool {
            if(p1.first<p2.first){
                return 1;
            }
            if(p1.first>p2.first){
                return 0; 
            }
            return p1.second>p2.second;
        };
        priority_queue<Pair,vector<Pair>, decltype(comp)> pq(comp); 
        for(auto itr=m.begin();itr!=m.end();itr++){
            pq.push(Pair(itr->second, itr->first)); 
        }
        vector<string> v;
        while(k--){
            v.push_back(pq.top().second); 
            pq.pop(); 
        }
        return v;
    }
};