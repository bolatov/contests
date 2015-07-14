#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    std::vector<int> v(100, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v[a]++;
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 1) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}