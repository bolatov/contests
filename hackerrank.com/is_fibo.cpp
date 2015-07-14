#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

bool isFibo(long long n, std::vector<long long>& v) {
  int lo = 0, hi = v.size() - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (v[mid] == n) {
      return true;
    } else if (v[mid] < n) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return false;
}

const long long MAX_N = 1e10 + 5;

int main(int argc, char const* argv[]) {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  vector<long long> v;
  v.push_back(0);
  v.push_back(1LL);
  while (v[v.size() - 1] <= MAX_N) {
    v.push_back(v[v.size() - 1] + v[v.size() - 2]);
  }
  int t;
  long long n;
  cin >> t;
  for (int itest = 0; itest < t; ++itest) {
    cin >> n;
    string ans = isFibo(n, v) ? "IsFibo" : "IsNotFibo";
    cout << ans << endl;
  }
  return 0;
}