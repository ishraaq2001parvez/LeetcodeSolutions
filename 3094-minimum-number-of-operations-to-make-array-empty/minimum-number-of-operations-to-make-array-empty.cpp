class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> m;
        for(int& i:nums) m[i]++; 
        int res=0 ;
        for(auto& [k,v]: m){
            if(v!=1){
                if(v==3 || v==2) res++; 
                else if (v==4) res+=2;
                else if((v-4)%3==0){
                    res+=(v-4)/3 + 2;
                }
                else if((v-2)%3==0){
                    res+=(v-2)/3+1;
                }
                else if(v%3==0){
                    res+=v/3;
                }
            }
            else return -1; 
        }
        return res;
    }
};