class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int index = 0;

        while(index < s.length()) {
            if(!ans.empty() && ans.back() == s[index]) {
                // pop from ans
                ans.pop_back();
            }
            else {
                ans.push_back(s[index]);
            }
            index++;
        }
        return ans;
    }
};