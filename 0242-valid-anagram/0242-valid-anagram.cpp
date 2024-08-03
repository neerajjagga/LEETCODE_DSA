class Solution {
public:
    bool isAnagram(string s, string t) {
        // Optimal Approach

        int freqTable[256] = {0};

        // count occurances of all characters in string s 
        for(int i=0; i<s.size(); i++) {
            // it automaticaly type cast char to int 
            freqTable[s[i]]++;
        }

        // count occurances of all characters in string t
        // we can also done it with making another freqTable for t
        // but we here decrement the count of character in freqTable
        // if all elements of freqTable is zero then two words are anagram of each other
        for(int i=0; i<t.size(); i++) {
            // it automaticaly type cast char to int 
            freqTable[t[i]]--;
        }

        // check all the elements of freqTable are zero or not

        for(int i=0; i<256; i++) {
            if(freqTable[i] != 0) {
                // means frequency of words is not matched
                return false;
            }
        }


        return true;





    //  BruteForce Approach
    // sort(s.begin(), s.end());
    // sort(t.begin(), t.end());

    // if(s == t) return true;

    // return false;

    }
};