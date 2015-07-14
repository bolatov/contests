#include <iostream>
#include <cstdio>

using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }

int main(int argc, char const *argv[]) {
  long long l, r;
  cin >> l >> r;
  for (long long a = l; a <= r; ++a) {
    for (long long b = a + 1; b <= r; ++b) {
      for (long long c = b + 1; c <= r; ++c) {
        if (gcd(a, b) == 1 && gcd(b, c) == 1 && gcd(a, c) != 1) {
          // printf("%I64d %I64d %I64d\n", a, b, c);
          cout << a << " " << b << " " << c << endl;
          return 0;
        }
      }
    }
  }
  puts("-1");
  return 0;
}