class Solution {
public:
    void sub(map<int,int>& m, int i){
        m[i]--; 
        if(m[i]==0){
            m.erase(m.find(i)); 
        }
    }
    bool isNStraightHand(vector<int>& hand, int g) {
        if(hand.size()%g!=0)return 0; 
        map<int ,int> m;
        for(int& i:hand){m[i]++;}
        while(m.size()!=0){
            auto itr=m.begin(); 
            int x=itr->first; 
            sub(m, x); 
            for(int i=1;i<g;i++){
                if(m.find(x+i)==m.end()){
                    return 0;
                }
                sub(m, x+i); 
            }
        }
        return 1;
    }
};