class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        map<int,int> m;
        for(int i=0;i<k;i++){
          m[nums[i]]++;
        }
        v.push_back(m.rbegin()->first); 
        for(int i=1;i+k<=nums.size();i++){
          m[nums[i-1]]--;
          if(m[nums[i-1]]==0){m.erase(m.find(nums[i-1]));}
          m[nums[i+k-1]]++;
          v.push_back(m.rbegin()->first);
        }
        return v;
    }
};