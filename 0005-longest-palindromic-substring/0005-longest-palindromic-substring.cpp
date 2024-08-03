class Solution {
public:

    bool isPalindrome(string &s, int start, int end) {

        while(start < end) {
            if(s[start] == s[end]) {
                start++;
                end--;
            }
            else return false;
        }
        return true;
    } 

    string longestPalindrome(string s) {
        string ans;

        // extract all substrings 

        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {

                if(isPalindrome(s, i, j)) {
                    string t = s.substr(i, j-i+1);
                    ans = t.size() > ans.size() ? t : ans;
                }
            }
        }
        return ans;
    }
};