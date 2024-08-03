class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
       int j = s.length() - 1;

  while(i < j) {

    if(i<j && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
     i++;
    }
    else if(i<j && !((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))) {
       j--;
    }
    else {
      swap(s[i], s[j]);
      i++;
      j--;
    }
  }

  return s;
    }
};