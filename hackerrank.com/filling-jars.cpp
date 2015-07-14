#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  long long n, m, a, b, k;
  cin >> n >> m;
  long long sum = 0;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> k;
    sum += (b - a + 1) * k;
  }
  cout << sum / n << endl;
  return 0;
}