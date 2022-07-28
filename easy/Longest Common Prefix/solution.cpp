class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp="";
        int k=-1,l=2000000000,n=strs.size();
        for(int i=0;i<n;i++){
            if(strs[i].length()<l){
                //get the length of the shortest string, and store the shortest string
                l=strs[i].length(),k=i;
            }
        }
        string ss=strs[k];
        // we only need to iterate over the letters of the shortest string
        for(int i=0;i<l;i++){
            bool active=true; // we are still checking
            for(int j=0;j<n;j++){
                // check all the strings if this letter is in the same position

                if(strs[j][i]!=ss[i]){
                    // letter is not in same position, so we break
                    active=false;break;
                }
            }
            if(active){
                // if letter is found in same position for all strings, add it to lcp
                lcp=lcp+string(1,ss[i]);
            }
            else{
                // at least one string did not have this letter in the same position
                break;
            }
        }
        return lcp;
    }
};