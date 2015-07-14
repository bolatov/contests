#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  std::vector<int> v(26, 0);
  for (char ch : s) {
    v[ch - 'a']++;
  }
  int cnt = 0;
  for (int i : v) {
    cnt += i % 2 == 1;
  }
  cout << (cnt <= 1 ? "YES" : "NO") << endl;
  return 0;
}