// solution using combination of bucket sort and sort
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        vector<vector<string>> v(100, vector<string>()); //create bucket for storing strings
        for(auto s:nums){
            v[s.length()-1].push_back(s); // append string to appropriate bucket based on length
        }
        for(auto& i:v){
            sort(i.begin(), i.end()); // sort each bucket
        }
        nums.clear(); 
        for(auto& i:v){
            for(auto j:i){
                nums.push_back(j); 
                // this process is the trickiest
                // we know that numbers with more length are greater than numbers of smaller length
                // and in between the numbers of smaller length, we have sorted them already
                // so the list will always be appended in increasing order
            }
        }
        return nums[nums.size()-k]; 
    }
};