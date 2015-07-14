#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}

int main(int argc, char const *argv[]) {
  int t, n;
  cin >> t;
  while (t-- > 0) {
    cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    bool yes = false;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (gcd(v[i], v[j]) == 1) {
          yes = true;
          break;
        }
      }
      if (yes) break;
    }
    cout << (yes ? "YES" : "NO") << endl;
  }
  return 0;
}