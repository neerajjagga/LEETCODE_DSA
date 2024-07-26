class Solution {
public:
// this function is normalizing the pattern as well all words of the string s to find which word is following the pattern or which is not
    void createMapping(string &str) {
        // find mapping
        char start = 'a';
        char mapping[300] = {0};

        for(auto ch: str) {
            if(mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }

        // update the string

        for(int i=0; i<str.length(); i++) {
            char ch = str[i];
            str[i] = mapping[ch];
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;

        // first normalize the pattern 
        createMapping(pattern);

        // then normalize all words of the vector string s;
        for(auto s: words) {

            // we first store the string in temp string because if it is the valid string we have to return the string as well 
            // but if we not store it, we will loose our string because we have to pass it to the createMapping function and we cannot return that string
            string tempString = s;

            createMapping(tempString);
            
            if(tempString == pattern) {
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};