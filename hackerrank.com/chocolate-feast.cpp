#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int t, n, c, m;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n >> c >> m;
    int answer = 0;

    int chocs = n / c;
    answer += chocs;
    int wrapper = chocs;
    while (wrapper >= m) {
      chocs = wrapper / m;
      answer += chocs;
      wrapper = chocs + (wrapper % m);
      printf("chocs=%d, wrapper=%d\n", chocs, wrapper);
    }
    cout << answer << endl;
  }
  return 0;
}