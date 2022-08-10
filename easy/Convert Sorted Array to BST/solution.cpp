/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(int left, int right, vector<int>& nums){
        if(left==right){
            return new TreeNode(nums[left]); 
        }
        else if(left==right-1){
            return new TreeNode(nums[right], dfs(left, right-1, nums), NULL); 
        }
        else{
            int mid=(left+right)/2; 
            return new TreeNode(nums[mid], dfs(left, mid-1, nums), dfs(mid+1, right, nums)); 
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(0, nums.size()-1, nums); 
    }
};