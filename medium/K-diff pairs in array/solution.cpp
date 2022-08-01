class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> m; // keep a map for storing the number of times a number occurs
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++; 
        }
        int s=0; // keep count
        for(auto itr=m.begin(); itr!=m.end();itr++){
            auto x=m.find(itr->first+k); // find k+num in the map
            if(x!=m.end()){ // if k+num has been found
                if(k==0){
                    // if k=0, then we only need to add if more than one occurrence of k+num exists
                    if(x->second>1){
                        s++;
                    }
                }
                else{
                    // else, simply increment
                    s++;
                }
            }
        }
        return s;
    }
};