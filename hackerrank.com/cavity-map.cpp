#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    std::vector<string> v(n), vs(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        vs[i] = v[i];
    }
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            char ch = v[i][j];
            if (ch > v[i - 1][j] && ch > v[i + 1][j] && ch > v[i][j - 1] &&
                ch > v[i][j + 1])
                vs[i][j] = 'X';
        }
    }
    for (string s : vs) {
        for (char ch : s)
            cout << ch;
        cout << endl;
    }
    return 0;
}