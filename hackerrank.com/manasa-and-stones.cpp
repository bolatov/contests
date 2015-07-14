#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
  int t, n, a, b;
  cin >> t;
  set<int> v;
  for (int itest = 0; itest < t; ++itest) {
    cin >> n >> a >> b;
    v.clear();
    for (int i = 0; i < n; ++i) {
      v.insert(i * a + (n - i - 1) * b);
    }
    for (set<int>::iterator it = v.begin(); it != v.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;
  }
  return 0;
}