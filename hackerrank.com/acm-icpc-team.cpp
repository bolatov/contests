#include <iostream>
#include <vector>

using namespace std;

string orop(string& s, string& t) {
  string r = "";
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1' || t[i] == '1')
      r += '1';
    else
      r += '0';
  }
  return r;
}

int ones(string& t) {
  int temp = 0;
  for (int i = 0; i < t.size(); ++i) {
    temp += (t[i] == '1');
  }
  return temp;
}

int main() {
  int n, m;
  cin >> n >> m;
  std::vector<string> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int topics = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      string t = orop(v[i], v[j]);
      topics = max(ones(t), topics);
    }
  }
  cout << topics << endl;

  int teams = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      string t = orop(v[i], v[j]);
      teams += ones(t) == topics;
    }
  }
  cout << teams << endl;

  return 0;
}