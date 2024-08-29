class Solution {
public:
    
    void removeOccRE(string &s, string &part) {
        // first found index where the part found
        int found = s.find(part);
        if(found != string::npos) {

            // extract left and right string
            string leftStr = s.substr(0, found);
            string rightStr = s.substr(found+part.length(), s.size());

            s = leftStr + rightStr;

            // recursive call
            removeOccRE(s, part);
        }
    }

    string removeOccurrences(string s, string part) {
        removeOccRE(s,part);
        return s;
    }
};