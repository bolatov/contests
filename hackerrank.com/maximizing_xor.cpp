#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
  int mval = 0;
  for (int a = l; a <= r; a++) {
    for (int b = a; b <= r; b++) {
      mval = max(mval, a ^ b);
    }
  }
  return mval;
}

int main() {
  int res;
  int _l;
  cin >> _l;

  int _r;
  cin >> _r;

  res = maxXor(_l, _r);
  cout << res;

  return 0;
}
