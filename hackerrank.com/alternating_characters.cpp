#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int maxSeq(string& s, char ch) {
  int res = 0;

  for (char c : s) {
    if (c == ch) {
      res++;
      ch = 'A' + ('B' - c);
    }
  }

  return res;
}

int main(int argc, char const* argv[]) {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  int t;
  string s;
  cin >> t;
  for (int itest = 0; itest < t; ++itest) {
    cin >> s;
    if (s.find('A') == string::npos || s.find('B') == string::npos) {
      cout << (s.size() - 1) << endl;
      continue;
    }

    int ans = max(maxSeq(s, 'A'), maxSeq(s, 'B'));
    cout << (s.size() - ans) << endl;
  }
  return 0;
}