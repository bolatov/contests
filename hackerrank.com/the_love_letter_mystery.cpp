#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  string s;
  for (int itest = 0; itest < t; ++itest) {
    cin >> s;
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
      ans += abs(s[i] - s[n - i - 1]);
    }
    cout << ans << endl;
  }
  return 0;
}