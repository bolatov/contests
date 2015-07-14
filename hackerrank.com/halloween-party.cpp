#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  long long k;
  while (t-- > 0) {
    cin >> k;
    cout << (k / 2) * (k - k / 2) << endl;
  }
  return 0;
}