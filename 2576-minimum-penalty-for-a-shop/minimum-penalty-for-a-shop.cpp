class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> y(customers.length()+1, 0), n(customers.length()+1, 0); 
        for(int i=1;i<=customers.length();i++){
            y[i]+=y[i-1]; n[i]+=n[i-1]; 
            if(customers[i-1]=='Y')y[i]++;
            if(customers[i-1]=='N')n[i]++;
        }

        vector<int> dp(customers.length()+1, 0); 
        dp[0] = y.back() - y[0]; dp.back() = n.back();
        for(int i=1;i<customers.length();i++){
            dp[i]  = y.back()- y[i] + n[i];  
        }

        return min_element(dp.begin(), dp.end()) - begin(dp); 
        
    }
};