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
  int a, b;
  cin >> a >> b;
  if (b >= a || b == 0) {
    puts("infinity");
    return 0;
  }
  int res = 0;
  a -= b;
  for (int i = 1; i * i <= a; ++i) {
    if (a % i == 0 && (a / i) > b) {
      res++;
    }
  }
  cout << res << endl;

  return 0;
}
