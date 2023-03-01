class Solution {
public:
    vector<int> a,b; 
    void merge(int l,int m,int r,vector<int>& v){
        a.clear(); b.clear(); 
        int i=0,j=0; 
        for(i=l;i<=m;i++){
            a.push_back(v[i]); 
        }
        for(int j=m+1;j<=r;j++){
            b.push_back(v[j]); 
        }
        i=0,j=0;int k=l;
        for(;i<a.size()&&j<b.size();){
            if(a[i]<b[j]){
                v[k++]=a[i++];
            }
            else{
                v[k++]=b[j++];
            }
        }
        for(;i<a.size();){v[k++]=a[i++]; }
        for(;j<b.size();){v[k++]=b[j++]; }
    }
    void mergesort(vector<int>& nums, int l, int r){
        if(l<r){
            mergesort(nums, l , (l+r)/2); mergesort(nums, (l+r)/2+1,r); 
            merge(l, (l+r)/2, r, nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1); 
        return nums;
    }
};