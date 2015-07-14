#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  long long a, b;
  std::vector<long long> v;
  for (int i = 1; i * i <= 1e9; ++i) {
    v.push_back(i * i);
  }
  while (t-- > 0) {
    cin >> a >> b;
    int i = lower_bound(v.begin(), v.end(), a) - v.begin();
    int j = upper_bound(v.begin(), v.end(), b) - v.begin();
    if (j >= v.size() || v[j] > b) j--;
    cout << j - i + 1 << endl;
  }
  return 0;
}