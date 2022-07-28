// first method by converting to string
bool isPalindrome(int x) {
    // to_string(x) converts int to string
    string s=to_string(x);
    string s1=s;
    // reverses string from strt iterator to end iterator
    reverse(s1.begin(),s1.end()); 
    
    return s==s1;
}


