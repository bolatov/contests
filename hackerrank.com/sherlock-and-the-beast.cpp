#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int t, n;
  cin >> t;
  std::vector<string> v;
  for (int itest = 0; itest < t; ++itest) {
    cin >> n;
    int ind = -1;
    for (int i = n; i >= 0; --i) {
      if (i % 3 == 0 && (n - i) % 5 == 0) {
        ind = i;
        break;
      }
    }
    string ans = "";
    if (ind >= 0) {
      for (int i = 0; i < ind; ++i) {
        ans += "5";
      }
      for (int i = ind; i < n; ++i) {
        ans += "3";
      }

    } else {
      ans = "-1";
    }
    cout << ans << endl;
  }
  return 0;
}