class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1);
        for(int i=0;2*i<=n;i++){
            v[2*i]=v[i];
            if(2*i+1<=n){
                v[2*i+1]=v[i]+1;
            }
        }
        return v;
    }
};