#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
  int t, n;
  cin >> t;
  for (int itest = 0; itest < t; ++itest) {
    cin >> n;
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
      if (i % 2) {
        ans *= 2;
      } else {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}