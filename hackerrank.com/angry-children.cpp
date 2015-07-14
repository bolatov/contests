#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int ans = v[v.size() - 1] - v[0];
  for (int i = 0, j = k - 1; j < n; ++i, ++j) {
    ans = min(ans, v[j] - v[i]);
  }
  cout << ans << endl;
  return 0;
}