vector<int> twoSum(vector<int>& nums, int target) {
  // we will use the two pointers method after sorting the array
  
  // first we will sort the array to ensure that 
  // the array is increasing
  sort(nums.begin(), nums.end()); 

  // for two pointers, we will 
  int l=0, r=nums.size()-1; 
  while(l<=r){
    if(arr[l]+arr[r]==target){
      return vector<int>{l,r}; 
    }
    else if(arr[l]+arr[r]>target){
      r--;
    }
    else{
      l++; 
    }
  }
  return vector<int>{-1, -1}; 
}
