int c(char c){
    //simply returns the corresponding number for each letter
    if(c=='I'){return 1;}
    else if(c=='V'){return 5;}
    else if(c=='X'){return 10;}
    else if(c=='L'){return 50;}
    else if(c=='C'){return 100;}
    else if(c=='D'){return 500;}
    else{return 1000;}
}

class Solution {
public:
    int romanToInt(string s) {
        int i=0,l=s.length(),x=0;
        //loop until second last digit
        //because two cases are possible - either last digit has been counted already, like "IX" 
        // or it is separate, like "X"
        while(i<l-1){
            if(c(s[i])<c(s[i+1])){
                // check if left int is smaller than right int
                // if so, we have a compound number, like "IX" or "XV"
                x=x+c(s[i+1])-c(s[i]);
                // "IX" = "X"- "I", number on left is subtracted from number on right
                i=i+2;
                // incremenet i by 2 because we have done a pair
            }
            else{
                // default case - simply add up the number
                x=x+c(s[i]);
                i++;
            }
        }
        if(i==l-1){
            // in case last number needs to be added
            x=x+c(s[i]);
        }
        return x;
    }
};