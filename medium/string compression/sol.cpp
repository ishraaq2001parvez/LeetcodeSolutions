class Solution {
public:
    int compress(vector<char>& chars) {
        int p=0, i=0, sum=0, j=0; 
        string s; 
        while(p<chars.size()){
            i=p;
            while(i<chars.size() && chars[i]==chars[p]){
                i++; 
                sum++; 
            }
            chars[j++]=chars[p];
            if(sum>1){
                s=to_string(sum); 
                for(char& c:s){
                    chars[j++]=c; 
                }
            }
            p=i;sum=0;
        }
        return j;
    }
};