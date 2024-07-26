class Solution {
public:
    static string str;
    static bool customComparator(char char1, char char2) {
        // This will return true, if position of char1 in str string is
        // less then the position of char 2 in str string


        // when true is returned, then char1 will be placed before char2 in the
        // output string
        return (str.find(char1) < str.find(char2));
    }
    string customSortString(string order, string s) {
        str = order;
        sort(s.begin(), s.end(), customComparator);
        return s;
    }
};
string Solution:: str;