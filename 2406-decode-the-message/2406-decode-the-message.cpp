class Solution {
public:
    string decodeMessage(string key, string message) {
        // create mapping

        // i know that my mapping always starts from
        char start = 'a';

        // to store mapping
        // and hr dabbe ke uper zero hona chahiye -> because 0 = null;
        char mapping[280] = {0};

        // yeh forEach loop apne app key ke saare elements pr triverse krega 
        // with auto we don't have to tell the type of the variable (in our case is ch);

        for(auto ch: key) {
            // that why we assign mapping = 0; 
            // to make sure that ki same character ki baar baar mapping na ho rhi ho
            if(ch != ' ' && mapping[ch] == 0) {
                mapping[ch] = start;
                start++;   
            }
        }
        // use mapping

        string ans;

        for(auto ch: message) {
            if(ch == ' ') {
                ans.push_back(' ');
            }
            else {
                 // i need decodedcharacter
                char decodedCharacter = mapping[ch];
                ans.push_back(decodedCharacter);
            }
        }
        return ans;
    }
};