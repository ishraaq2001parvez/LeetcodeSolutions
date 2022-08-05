class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> q; //maintain queue for inserting greater elements in correct order
        vector<int> v; 
        int no=0; // for number of pivots
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot){
                q.push(nums[i]); 
            }
            else if(nums[i]==pivot){
                no++;
            }
            else {
                v.push_back(nums[i]); 
            }
        }
        while(no--){
            v.push_back(pivot); 
        }
        while(!q.empty()){
            v.push_back(q.front()); //pop all in order of appearance, insert
            q.pop(); 
        }
        return v;
    }
};