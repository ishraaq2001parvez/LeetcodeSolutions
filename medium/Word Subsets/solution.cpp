class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char, int> m1,m2; //two maps for traversal
        for(string s:words2){
            // we will maintain a special strategy 
            // we will store only the max count of a character for the entire list
            // so we dont need to traverse the whole list of words2 to check if they all 
            // are subset of a word

            m2.clear(); 
            for(char c:s){
                m2[c]++; 
            }
            for(auto itr=m2.begin(); itr!=m2.end();itr++){
                // check if char is there
                // if not, add it
                // if there, max out the value
                if(m1.find(itr->first)!=m1.end()){
                    m1[itr->first]=max(itr->second, m1[itr->first]); 
                }
                else{
                    m1[itr->first]=itr->second;
                }
            }
        }
        // for(auto itr=m1.begin();itr!=m1.end();itr++){
        //     printf("%c= %d\n", itr->first, itr->second); 
        // }
        // cout<<endl;
        vector<string> v;
        for(string s:words1){
            m2.clear(); 
            // insert chars into map
            for(char c:s){
                m2[c]++; 
            }
            // loop over all characters of words2, see if they can be a subset of this word
            bool is=true; 
            for(auto itr=m1.begin(); itr!=m1.end();itr++){
                if(m2.find(itr->first)!=m2.end()){
                    if(m2[itr->first]<itr->second){
                        is=false;
                    }
                }
                else {
                    is=false;
                }
                // printf("%c= %d\n", itr->first, itr->second); 
            }
            if(is){
                v.push_back(s);
            }
            // printf("\n"); 
        }
        return v;
        
    }
};
