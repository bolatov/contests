class Solution {
  public:
    string reverseString(string s) {
        string t = "";
        for (int i = s.size() - 1; i >= 0; i--)
            t += s[i];
        return t;
    }
};