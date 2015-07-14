#include <iostream>

using namespace std;

long long cnt1, cnt2, x, y;
bool f(long long v) {
  long long f1 = v / x;
  long long f2 = v / y;
  long long both = v / (f1 * f2);
  long long rest = v - f1 - f2 + both;
  f1 -= both;
  f2 -= both;
  f2 = (cnt1 - f2) < 0 ? 0 : cnt1 - f2;
  f1 = (cnt2 - f1) < 0 ? 0 : cnt2 - f1;
  return f1 + f2 <= rest;
}

int main(int argc, char const *argv[]) {
  cin >> cnt1 >> cnt2 >> x >> y;

  long long ans = 0;
  long long lo = 0, hi = 1e18;
  while (lo <= hi) {
    long long mid = lo + (hi - lo) / 2;
    cout << mid << endl;
    if (f(mid)) {
      hi = mid - 1;
      ans = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << ans << endl;

  return 0;
}