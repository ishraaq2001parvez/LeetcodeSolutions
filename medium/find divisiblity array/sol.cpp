class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> v(word.length(), 0);
        long long r=0, n, p=0; 
        for(char& c:word){
            n=c-'0';
            r=(r*10+n%m)%m; 
            v[p++]=(r==0);
        }
        return v;
    }
};