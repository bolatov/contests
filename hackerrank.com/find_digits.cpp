#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  long long n;
  cin >> t;
  for (int itest = 0; itest < t; ++itest) {
    cin >> n;
    long long ans = 0, nc = n;
    while (nc > 0) {
      long long q = nc % 10;
      nc /= 10;
      if (q > 0 && n % q == 0) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}