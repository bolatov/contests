#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
string toString(T t) {
  stringstream ss;
  ss << t;
  return ss.str();
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  std::vector<int> v;
  int i = 0;
  int j = 0;
  bool no = false;
  for (char c : s) {
    if (c == '(')
      i++;
    else if (c == '#') {
      v.push_back(1);
      i--;
    } else {
      i--;
    }
  }
  if (i > 0 || no) {
    puts("-1");
  } else {
    for (int vi : v) {
      cout << vi << endl;
    }
  }
  return 0;
}
